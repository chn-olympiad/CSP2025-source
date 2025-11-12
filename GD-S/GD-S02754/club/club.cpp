#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int T,n;
struct go
{
	int w,v;
}a[1000001][3];
bool cmp(go a,go b)
{
	return a.v>b.v;
}
int cnt[3];
signed main()
{
//	freopen("club5.in","r",stdin);
//	freopen("club5.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=2;j++) a[i][j].w=j; 
			cin>>a[i][0].v>>a[i][1].v>>a[i][2].v;
			sort(a[i],a[i]+3,cmp);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cnt[a[i][0].w]++;
			ans+=a[i][0].v;
//			cerr<<"IN"<<a[i][0].w<<"\n";
		}
		int wc=0;
		if(max(cnt[0],max(cnt[1],cnt[2]))>n/2)
		{
			vector <pair<int,int> > mover;
			for(int i=1;i<=n;i++)
			{
				if(cnt[a[i][wc].w]>n/2)
				{
					mover.push_back({a[i][wc].v-a[i][wc+1].v,i});
				}
			}
			sort(mover.begin(),mover.end());
			reverse(mover.begin(),mover.end());
			while(max(cnt[0],max(cnt[1],cnt[2]))>n/2)
			{
				int w=mover.back().second;
				ans-=mover.back().first;
				cnt[a[w][wc].w]--;
				cnt[a[w][wc+1].w]++;
//				cerr<<"OUT "<<a[w][wc].w<<" ";
//				cerr<<"IN "<<a[w][wc+1].w<<" "<<mover.back().first<<"\n";
				mover.pop_back();
			}
		}
		cout<<ans<<"\n";
//		cerr<<ans<<"\n";
	}
}
/*
贪心是对的
一级违法就放二级，按 delta 贪心 
*/
