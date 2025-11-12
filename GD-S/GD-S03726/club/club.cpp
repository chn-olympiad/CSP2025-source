#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
using namespace std;
int T,n,m,limit,ans;
int t[4];
int a[100005][4];
int maxx[100005],max_pos[100005];
int p_max[100005],p_max_pos[100005];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n,limit=n/2,ans=0,t[1]=t[2]=t[3]=0;
		rep(i,1,n) 
		{
			p_max[i]=p_max_pos[i]=max_pos[i]=maxx[i]=0;
			rep(j,1,3) 
			{
				cin>>a[i][j];
				if(maxx[i]<=a[i][j])
				{
					p_max[i]=maxx[i],p_max_pos[i]=max_pos[i];
					maxx[i]=a[i][j],max_pos[i]=j;
				}
				else if(p_max[i]<=a[i][j])
				{
					p_max[i]=a[i][j],p_max_pos[i]=j;
				}
			}
		}
		// if(n<=10)
		// {
		// 	dfs(1,0,0,0,0);
		// 	cout<<ans<<'\n';
		// 	continue;
		// }
		priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > p;
		rep(i,1,n) ans+=maxx[i],t[max_pos[i]]++,p.push({maxx[i]-p_max[i],{p_max_pos[i],max_pos[i]}});
		// rep(i,1,n) cout<<maxx[i]<<" "<<max_pos[i]<<"    "<<p_max[i]<<" "<<p_max_pos[i]<<' '<<maxx[i]-p_max[i]<<"\n";
		while(t[1]>limit||t[2]>limit||t[3]>limit)
		{
			int pos=0;
			if(t[1]>limit) pos=1;
			if(t[2]>limit) pos=2;
			if(t[3]>limit) pos=3;
			// cout<<p.top().first<<" "<<p.top().second<<'\n';
			if(pos!=p.top().second.second)
			{
				p.pop();
				continue;
			}
			t[pos]--,ans-=p.top().first,t[p.top().second.first]++,p.pop();
		}
		cout<<ans<<"\n";
	}
}