#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 20;
const int M = 1e3 + 20;
int n,m,k;
long long pre[10];
struct strc{
	long long u,v,w;
}a[N];
long long b[13][N],f[N];
int cnt = 0,cntt = 0;
long long mx = 1e18;
int fl[20];
bool cmp(strc x,strc y){
	return x.w < y.w;
}
int fa[N];
int find(int x){
	while(fa[x] != x){
		x = fa[x];
		fa[x] = fa[fa[x]];
	}
	return x;
}
vector<int> v,son[N];
long long ans = 0;
void kruskal(){
	sort(a+1,a+1+cnt,cmp);
	int lst = n-1;
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= cnt;i++){
		int p = find(a[i].u),q = find(a[i].v);
		if(p == q) continue;
		else if(lst > 0){
			fa[p] = q;
			ans += a[i].w;
			v.push_back(i);
			lst--;
		}
	}
	return ;
}
vector<int> tmp,tmp2;
int cnt2,cnt3;
int flg[M][M],flg2[N];
void dfs(int x,int fa){
	int len = son[x].size();
	tmp.push_back(x);
	for(int i = 0;i < len;i++){
		if(son[x][i] == fa) continue;
		else if(son[x][i] == cnt2 || son[x][i] == cnt3 || flg[x][son[x][i]] == 0) continue;
		else dfs(son[x][i],x); 
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		scanf("%lld%lld%lld",&pre[1],&pre[2],&pre[3]);
		a[++cnt].u = pre[1],a[cnt].v = pre[2],a[cnt].w = pre[3];
		a[++cnt].u = pre[2],a[cnt].v = pre[1],a[cnt].w = pre[3];
	}
	for(int i = 1;i <= k;i++){
		scanf("%lld",&f[i]);
		for(int j = 1;j <= n;j++) scanf("%lld",&b[i][j]);
	}
	if(k == 0){
		kruskal();
		cout << ans;
		return 0;
	}else if(n <= 1e3){
		kruskal();
		/*int len = v.size();
		for(int i = 0;i < len;i++){
			son[a[v[i]].u].push_back(a[v[i]].v);
			son[a[v[i]].v].push_back(a[v[i]].u);
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++) flg[i][j] = 0;
		}
		for(int i = 1;i <= k;i++) fl[i] = 0;
		for(int i = 0;i < len;i++){
			long long ans1 = a[v[i]].w;
			tmp.clear();
			dfs(1,-1);
			long long my_answ_f = 1e18,my_answ_s = 1e18;
			for(int j = 1;j <= k;j++){
				for(int kt = 1;kt <= n;kt++) flg2[kt] = 0;
				if(fl[j] == 0){
					int len = tmp.size();
					long long my_answ_t = 1e18,my_answ_fth = 1e18;
					for(int kt = 0;kt < len;kt++){
						my_answ_t = min(my_answ_t,b[j][tmp[kt]]);
						flg2[tmp[kt]] = 1;
					}
					for(int kt = 1;kt <= n;kt++){
						if(flg[kt] == 0){
							my_answ_fth = min(my_answ_fth,b[j][kt]);
						}
					}
					my_answ_f = min(my_answ_f,my_answ_t + my_answ_fth + f[j]);
				}else{
					for()
				}
			}
		}*/
		
	}
	return 0;
}
