#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define req(i,a,b) for(int i(a);i>=(b);--i)
// #define sort stable_sort
using namespace std;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int T; cin>>T;
	while(T--)
	{
		int n,init_ans=0; cin>>n;
		vector<array<int,3>> sat(n);
		vector<vector<int>> p(3);
		for(auto &[x,y,z]:sat) cin>>x>>y>>z;
		rep(i,0,n-1)
		{
			int mxpos=0;
			if(sat[i][1]>sat[i][mxpos]) mxpos=1;
			if(sat[i][2]>sat[i][mxpos]) mxpos=2;
			p[mxpos].push_back(i),init_ans+=sat[i][mxpos];
		}
		int cap=n/2;
		if((int)p[0].size()<=cap&&(int)p[1].size()<=cap&&(int)p[2].size()<=cap)
		{
			cout<<init_ans<<'\n';
			continue;
		}
		int over=(int)p[0].size()>cap?0:(int)p[1].size()>cap?1:2;
		vector<int> loss(p[over].size());
		rep(idx,0,(int)loss.size()-1)
		{
			int mxv=-1,i=p[over][idx];
			rep(pos,0,2) if(over!=pos&&sat[i][pos]>mxv) mxv=sat[i][pos];
			loss[idx]=sat[i][over]-mxv;
		}
		sort(loss.begin(),loss.end());
		cout<<(init_ans-accumulate(loss.begin(),loss.begin()+(int)p[over].size()-cap,0ll))<<'\n';
	}
	return 0;
}
