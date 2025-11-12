#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5];
long long ans=0;
priority_queue<int> q[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(register int i=1;i<=n;++i)
		{
			int maxx=-1,t=0,cnt=1e9+5;
			for(register int j=1;j<=3;++j)
			{
				cin>>a[i][j];
				if(a[i][j]>maxx) maxx=a[i][j],t=j;
			}
			for(register int j=1;j<=3;++j)
				if(j!=t) cnt=min(cnt,abs(a[i][j]-maxx));
			ans+=maxx; q[t].push(-cnt);
		}
		while(q[1].size()>n/2) { ans+=q[1].top(); q[1].pop(); }
		while(q[2].size()>n/2) { ans+=q[2].top(); q[2].pop(); }
		while(q[3].size()>n/2) { ans+=q[3].top(); q[3].pop(); }
		cout<<ans<<endl;
		ans=0;
		for(register int i=1;i<=3;++i)
			while(!q[i].empty()) q[i].pop();
	}
	return 0;
 } 
