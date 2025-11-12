#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
struct edge{
	ll s,e,x;
	bool operator < (const edge& b) const{
		return x < b.x;
	}
};
ll n,m,k,N,ans = 1e18;
ll fa[10005],val[10005];
edge E_[1000005],E[110005],e[15][10005],tmp[110005];

ll find_root(ll x){
	if(fa[x] == x) return x;
	return fa[x] = find_root(fa[x]);
}

void unionn(ll x,ll y){
	x = find_root(x);
	y = find_root(y);
	if(x != y){
		fa[x] = y;
	}
	return ;
}

ll solve(){
	ll sum = 0;
	for(int i = 1;i <= n + k;i++) fa[i] = i;
	sort(E + 1,E + N + 1);
	for(int i = 1;i <= N;i++){
		if(find_root(E[i].s) != find_root(E[i].e)){
			unionn(E[i].s,E[i].e);
			sum += E[i].x;
		}
	}
	return sum;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++) fa[i] = i; 
	for(int i = 1;i <= m;i++){
		cin >> E_[i].s >> E_[i].e >> E_[i].x;
	}
	for(int i = 1;i <= k;i++){
		cin >> val[i];
		for(int j = 1;j <= n;j++){
			cin >> e[i][j].x;
			e[i][j].s = j;
			e[i][j].e = n + i; 
		}
		sort(e[i] + 1,e[i] + n + 1);
	} 
//	for(int i = 1;i <= m;i++) E[i] = E_[i];
	sort(E_ + 1,E_ + 1 + m);
	for(int i = 1;i <= m;i++){
		if(find_root(E_[i].s) != find_root(E_[i].e)){
			E_[++N] = E_[i];
			unionn(E_[i].s,E_[i].e);
		}
	}
	for(int i = 0;i < (1 << k);i++){
		ll cnt = 0;
		N = n - 1;
		for(int j = 1;j <= N;j++) E[j] = E_[j];
		for(int j = 1;j <= k;j++){
			if((i >> (j - 1)) & 1){
				cnt += val[j];
				ll top1 = 1,top2 = 1,top3 = 0;
				while(top1 <= N && top2 <= n){
					if(E[top1].x < e[j][top2].x){
						tmp[++top3] = E[top1++];
					}else{
						tmp[++top3] = e[j][top2++];
					}
				}
				while(top1 <= N){
					tmp[++top3] = E[top1++];
				}
				while(top2 <= n){
					tmp[++top3] = e[j][top2++];
				}
				for(int i = 1;i <= top3;i++){
					E[i] = tmp[i];
				} 
				N = top3;
			}
		}
		ans = min(ans,solve() + cnt);
	}
	cout << ans;
	return 0;
}
