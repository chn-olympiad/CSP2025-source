#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int tot[4];
int s[N][4];
int a[N][4];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
		tot[1]=tot[2]=tot[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int maxx=-1,op=0;
			for(int j=1;j<=3;j++)
				if(a[i][j]>maxx)maxx=a[i][j],op=j;
			tot[op]++,s[tot[op]][op]=i,ans+=maxx;
		}
		int maxx=n/2,op=0;
		for(int i=1;i<=3;i++)
			if(tot[i]>maxx)maxx=tot[i],op=i;
		if(!op)
		{
			cout<<ans<<"\n";
			continue;
		}
		int m=tot[op];
		priority_queue<int>q;
		for(int i=1;i<=m;i++)
		{
			int minn=200000,now=s[i][op];
			for(int j=1;j<=3;j++)
				if(j!=op&&a[now][op]-a[now][j]<minn)
					minn=a[now][op]-a[now][j];
			q.push(-minn);
		}
		while(tot[op]>n/2)
		{
			int now=q.top();q.pop();
			ans+=now,tot[op]--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
