#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e5+5, NN=1e2+5;
int n, f[2][NN][NN][NN], a[N][3];
pair<int, int> b[N<<1];
int cnt[3];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		int h=n/2;
//		priority_queue<tuple<int, int, int>> q;
		for(int i=1;i<=n;++i) {
			for(int j=0;j<3;++j)
				cin>>a[i][j];
//			q.push(tuple<int, int, int>{a[i][0], i, 0});
//			q.push(tuple<int, int, int>{a[i][1], i, 1});
//			q.push(tuple<int, int, int>{a[i][2], i, 2});
		}
		int res=0;
		if(n>200) {
//			cerr<<"H";
			priority_queue<int> q;
			for(int i=1;i<=n;++i) {
				q.push(a[i][0]);
			}
			while(h--)	res+=q.top(), q.pop();
			cout<<res<<'\n';
			continue;
			vector<tuple<int, int, int>> v;
			set<pair<int, int>> s[3][3];
			for(int i=1;i<=n;++i)
				for(int j=0;j<3;++j)
					v.push_back({a[i][j], i, j});
			sort(begin(v), end(v), greater<>());
			for(auto it=begin(v); it!=end(v); ++it) {
				int w, i, j;
				tie(w, i, j)=*it;
				bool fl=0;
				if(cnt[j]<h) {
					res+=w;
					++cnt[j];
					fl=1;
				} else {
					int _k=-1, _wk=-1, upd=0;
					for(int k=0;k<3;++k)
						if(k!=j && cnt[k]<h) {
							int wk=w-a[i][k];
							auto it=s[j][k].lower_bound(pair<int, int>{wk, 0});
							if(it!=s[j][k].begin()) {
								--it;
								if(a[(it)->second][k]-a[(it)->second][j]>upd) {
									upd=a[(it)->second][k]-a[(it)->second][j];
									_k=k, _wk=wk;
								}
							}
						}
					if(upd>0) {
					fl=1;
					res+=w+upd;
					auto it=--s[j][_k].lower_bound(pair<int, int>{_wk, 0});
					int _w=a[(it)->second][_k];
					for(int k=0;k<3;++k)
						if(k!=_k)
							s[_k][k].insert({_w-a[(it)->second][k], (it)->second});
					s[j][_k].erase(it);
					}
				}
				if(fl)
					for(int k=0;k<3;++k)
						if(k!=j)
							s[j][k].insert({w-a[i][k], i});
			}
			cout<<res<<'\n';
		}
		memset(f, 0, sizeof(f));
		for(int p=1;p<=n;++p) {
			memset(f[p&1], 0, sizeof(f[p&1]));
			int lim=min(n, p);int lim2=min(h, p);
			for(int i=0;i<=lim2;++i)
				for(int j=0;j<=lim2&&i+j<=lim;++j)
					for(int k=0;k<=lim2&&i+j+k<=lim;++k) {
						if(i)
							f[p&1][i][j][k]=max(f[p&1][i][j][k], f[p&1^1][i-1][j][k]+a[p][0]);
						if(j)
							f[p&1][i][j][k]=max(f[p&1][i][j][k], f[p&1^1][i][j-1][k]+a[p][1]);
						if(k)
							f[p&1][i][j][k]=max(f[p&1][i][j][k], f[p&1^1][i][j][k-1]+a[p][2]);
//						cerr<<"i "<<i<<" "<<j<<" "<<k<<"  "<<f[p&1][i][j][k]<<endl;
					}
		}
		for(int i=0;i<=h;++i)
			for(int j=0;j<=h&&i+j<=n;++j)
				for(int k=0;k<=h&&i+j+k<=n;++k)
					res=max(res, f[n&1][i][j][k]);
		cout<<res<<'\n';
//		memset(cnt, 0, sizeof(cnt));
//		int res=0;
//		while(!q.empty()) {
//			int A, i, j;
//			tie(A, i, j)=q.top();
//			q.pop();
//			if(cnt[j]<h) {
//				res+=A;
//				++cnt[j];
//			} else {
//				
//			}
//		}
	}
	return 0;
}

