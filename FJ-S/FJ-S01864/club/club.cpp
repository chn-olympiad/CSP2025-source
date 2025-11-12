#include<bits/stdc++.h>
using namespace std;
int a1[100005],a2[100005],a3[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T,n,t1,t2,t3,p1,p2,p3;
	long long ans;
	cin>>T;
	while(T--)
	{
		p1=0;
		p2=0;
		p3=0;
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>t1>>t2>>t3;
			if(max(t1,max(t2,t3))==t1)
			{
				a1[p1++]=t1-max(t2,t3);
				ans+=t1;
			}
			else if(max(t1,max(t2,t3))==t2)
			{
				a2[p2++]=t2-max(t1,t3);
				ans+=t2;
			}
			else if(max(t1,max(t2,t3))==t3)
			{
				a3[p3++]=t3-max(t2,t1);
				ans+=t3;
			}
		}
		if(p1>n/2)
		{
			sort(a1,a1+p1);
			for(int i=0;i<p1-n/2;i++)
			{
				ans-=a1[i];
			}
		}
		else if(p2>n/2)
		{
			sort(a2,a2+p2);
			for(int i=0;i<p2-n/2;i++)
			{
				ans-=a2[i];
			}
		}
		else if(p3>n/2)
		{
			sort(a3,a3+p3);
			for(int i=0;i<p3-n/2;i++)
			{
				ans-=a3[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
