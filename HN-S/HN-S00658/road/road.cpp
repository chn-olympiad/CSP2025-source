#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4;
const int MAXN = 1e18;
struct node{
	int u,v,w;
}s[N * 100];
int c[12],fa[N];
bool f[N];
inline bool cmp(const node& u , const node& v){
	return u.w < v.w;
}
inline int find(int x){
	if(x == fa[x])return x;
	return fa[x] = find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	int cnt = 0;
	for(int i = 1;i <= m;i ++){
		cin >> s[i].u >> s[i].v >> s[i].w;
		cnt ++;
	}
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++){
			int x;
			cin >> x;
			s[++ cnt] = (node){n + i , j , x};
		}
	}
	sort(s + 1 , s + cnt + 1 , cmp);
	int ans = MAXN;
	for(int i = 0;i < (1 << k);i ++){
		int num = n,sum = 0;
		for(int j = 1;j <= n;j ++)
			fa[j] = j;
		for(int j = 1;j <= k;j ++){
			if((i >> (j - 1)) & 1){
				f[j] = true;
				fa[j + n] = j + n;
				num ++;
				sum += c[j];
			}
			else f[j] = false;
		}
		for(int j = 1;j <= cnt,num > 1;j ++){
			int a = s[j].u,b = s[j].v;
			if(a > n && !f[a - n])
				continue;
			int la = find(a),lb = find(b);
			if(la == lb)continue;
			fa[la] = lb;
			-- num;
			sum += s[j].w;
		}
		ans = min(ans , sum);
	}
	cout << ans << "\n";
	return 0;
}
