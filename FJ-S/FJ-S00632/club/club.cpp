#include<bits/stdc++.h>
using namespace std;
long long t,n,ip[100010][3],ans;
struct dd{
	long long d[100010],dl;
	void ad(int j)
	{
		d[++dl]=j;
		for(int i=dl;i>1;i>>=1)
			if(d[i>>1]>d[i])
				swap(d[i>>1],d[i]);
		return;
	}
	void del()
	{
		if(dl!=1)swap(d[1],d[dl]);
		--dl;
		for(int i=1;(i<<1)<=dl;)
			if((i<<1|1)>dl)
				if(d[i<<1]<d[i])
					swap(d[i<<1],d[i]),i<<=1;
				else
					break;
			else
				if(d[i<<1]<d[i] || d[i<<1|1]<d[i])
					if(d[i<<1]<d[i<<1|1])
						swap(d[i<<1],d[i]),i<<=1;
					else
						swap(d[i<<1|1],d[i]),i=i<<1|1;
				else
					break;
		return;
	}
}que[3];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;ans=0;
		que[0].dl=que[1].dl=que[2].dl=0;
		for(int i=1;i<=n;i++)
		{
			cin>>ip[i][0]>>ip[i][1]>>ip[i][2];
			if(max(max(ip[i][0],ip[i][1]),ip[i][2])==ip[i][0])
			{
				ans+=ip[i][0];
				que[0].ad(ip[i][0]-max(ip[i][1],ip[i][2]));
				if(que[0].dl>n/2)
				{
					ans-=que[0].d[1];
					que[0].del();
				}
			}
			else if(max(ip[i][1],ip[i][2])==ip[i][1])
			{
				ans+=ip[i][1];
				que[1].ad(ip[i][1]-max(ip[i][0],ip[i][2]));
				if(que[1].dl>n/2)
				{
					ans-=que[1].d[1];
					que[1].del();
				}
			}
			else
			{
				ans+=ip[i][2];
				que[2].ad(ip[i][2]-max(ip[i][0],ip[i][1]));
				if(que[2].dl>n/2)
				{
					ans-=que[2].d[1];
					que[2].del();
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
