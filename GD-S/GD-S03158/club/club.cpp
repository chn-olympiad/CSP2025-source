#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3];
int cs[N];
int t,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				cin>>a[i][j];
		int ans=0,d=4,num[3]={0,0,0};
		for(int i=1;i<=n;i++)
		{
			pair<int,int> x[3]={{a[i][0],0},{a[i][1],1},{a[i][2],2}};
			sort(x,x+3);
			ans+=x[2].first,cs[i]=x[2].second,num[x[2].second]++;
		}
		for(int i=0;i<3;i++)
			if(num[i]>n/2) d=i;
		if(d==4) cout<<ans<<"\n";
		else
		{
			priority_queue<int> q;
			for(int i=1;i<=n;i++)
				if(cs[i]==d)
				{
					int x=0;
					for(int j=0;j<3;j++)
						if(j!=d) x=max(x,a[i][j]); 
					q.push(x-a[i][d]);
				}
			while(num[d]>n/2) ans+=q.top(),q.pop(),num[d]--;
			cout<<ans<<"\n";
		}
	}
	return 0;
}
