#include <bits/stdc++.h>
#define ll long long
constexpr int N = 2e6 + 5;
using namespace std;
struct node{
	int u,v,w;
}e[N],to[N];
map<pair<int,int>,int>mp;
int n,m,k,f[N],cnt = 1,tot = 0,a[20][10005];
ll ans = 0;
int find(int x){
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}
bool add(int x,int y,int w,ll &sum){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy){
		f[fx] = f[fy];
		sum += w;
		return 1;
	}
	return 0;
} 
void add2(int k){
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j < i; j ++){
			to[++tot] = (node){i , j , a[k][i] + a[k][j]};
//			cout << i <<" " << j << " " << a[k][i] + a[k][j] << '\n';
		}
	}
}
bool cmp(node x,node y){
	return x.w < y.w;
}
int main(){
//	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for(int i = 1 ; i <= k ; i ++){
		for(int j = 0 ; j <= n ; j ++){
			cin >> a[i][j];
		}
	}
	for(int i = 1 ; i <= n ; i ++) f[i] = i;
	sort(e + 1,e + m + 1 ,cmp);
	for(int i = 1 ; i <= m ; i ++){
		if(add(e[i].u , e[i].v , e[i].w , ans))
			cnt += 1;
		if(cnt >= n)
			break;
	}
	for(int i = 1 ; i < (1 << k) ; i ++){
//		memset(to,0,tot + 5);
		tot = 0; cnt = 1;
		ll val = 0;
		for(int i = 1 ; i <= n ; i ++) f[i] = i;
		for(int j = 0 ; j < k ; j ++){
//			cout << (i & (1 << j));
			if(i & (1 << j)){
				add2(j + 1);
//				cout << j + 1 <<'\n';
				val += a[j + 1][0];
//				cout << a[j][0] <<'\n';
			}
//			cout<<'\n';
		}
		sort(to + 1 ,to + tot + 1, cmp);
		int l = 1 , r = 1;
//		cout << val <<'\n';
		while(cnt < n){
			if(e[l].w < to[r].w){
//				cout << val <<"->";
				if(add(e[l].u , e[l].v , e[l].w , val))
					cnt += 1;
				l ++; 
//				cout << val <<" " << e[l].u <<" "<< e[l].v <<" "<< e[l - 1].w <<'\n';
//				cout << e[l].u <<" "<< e[l].v <<" "<< e[l].w <<" "<< val<<'\n';
			}
			else {
//				cout << val <<"->";
				if(add(to[r].u , to[r].v , to[r].w , val))
					cnt += 1;
				r ++;
//				cout << val <<" " << e[l].u <<" "<< e[l].v <<" "<< e[l].w <<'\n';
//				cout << val <<" " << to[r].u <<" "<< to[r].v <<" "<< to[r - 1].w <<" "<<'\n';
			}
		}
		ans = min(ans , val); 
//		cout << fuza <<'\n';
	}
	cout << ans; 
	return 0;
} 

