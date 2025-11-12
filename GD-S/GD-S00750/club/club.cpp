#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define rep(i,a,b) for(int i = (a);i <= (b);++i)

using ll = long long;

const int N = 1e5 + 5;

int T,n,m,col[N],cnt[3];
ll a[N][3],ans;
priority_queue<pair<ll,int> > Q[3][3];

void ins(int x,int c){
//	printf("ins %d %d\n",x,c);
	if(~col[x]) --cnt[col[x]],ans -= a[x][col[x]];
	col[x] = c,++cnt[c],ans += a[x][c];
	rep(d,0,2) if(d != c) Q[c][d].emplace(a[x][d] - a[x][c],x);
}

int main(){
//	return system("fc club5.ans club.out");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(scanf("%d",&T);T--;){
		scanf("%d",&n),m = n / 2,ans = 0;
		rep(i,1,n) rep(j,0,2) scanf("%d",a[i] + j);
		rep(i,0,2) cnt[i] = 0;
		rep(i,0,2) rep(j,0,2) while(Q[i][j].size()) Q[i][j].pop();
		rep(i,1,n) col[i] = -1;
		rep(i,1,n){
			int j = max_element(a[i],a[i] + 3) - a[i];
			if(cnt[j] == m){
				ll v0 = -1e18,v1 = -1e18; int p0 = -1,p1 = -1;
				rep(x,0,2) if(x != j && a[i][x] - a[i][j] > v1)
					v1 = a[i][x] - a[i][j],p1 = x;
				rep(x,0,2) if(x != j){
					while(Q[j][x].size() && col[Q[j][x].top().se] != j) Q[j][x].pop();
					if(Q[j][x].size() && Q[j][x].top().fi > v0) v0 = Q[j][x].top().fi,p0 = x;
				}
				if(v1 > v0) j = p1;
				else {
					int k = Q[j][p0].top().se; Q[j][p0].pop();
					ins(k,p0);
				}
			}
			ins(i,j);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
