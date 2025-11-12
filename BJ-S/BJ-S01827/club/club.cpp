#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],maxn,sec,cnt1,cnt2,cnt3,p[N],opt,c;
ll ans;
priority_queue<int>q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			maxn=0,p[i]=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>maxn)
				{
					maxn=a[i][j];
					p[i]=j;
				}
			}
			ans+=maxn;
			if(p[i]==1)cnt1++;
			else if(p[i]==2)cnt2++;
			else if(p[i]==3)cnt3++;
		}
		opt=0,c=0;
		if(cnt1>n/2)opt=1,c=cnt1;
		else if(cnt2>n/2)opt=2,c=cnt2;
		else if(cnt3>n/2)opt=3,c=cnt3;
		c-=n/2;
		if(!opt)
		{
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(p[i]!=opt)continue;
			if(opt==1)q.push(max(a[i][2],a[i][3])-a[i][1]);
			else if(opt==2)q.push(max(a[i][1],a[i][3])-a[i][2]);
			else if(opt==3)q.push(max(a[i][1],a[i][2])-a[i][3]);
		}
		for(int i=1;i<=c;i++)
		{
			ans+=q.top();
			q.pop();
		}
		while(!q.empty())q.pop();
		cout<<ans<<'\n';
	}
	return 0;
}
