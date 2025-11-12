#include<bits/stdc++.h>
#define int long long
using namespace std;
bool MB1;
const int N = 2e4+10;
const int M = 2e6+10;
const int K = 15;
struct node{
	int u,v,w;
}e[5 * M],E[5 * M],ed[N];
int fa[N],n,m,k,c[K],a[K][N],top;
bool MB2;
bool cmp(node a,node b){
	return a.w < b.w;
}
int Find(int x){
	if(fa[x] == x) return fa[x];
	else return fa[x] = Find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	cout<<(&MB1 - &MB2)/1024.0/1024.0<<endl;
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)
		fa[i] = i;
	for(int i = 1;i<=m;i++){
		int u; cin>>u;
		int v; cin>>v;
		int w; cin>>w;
		e[i] = {u,v,w};
	}
	bool flag = true;
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		if(c[i] != 0) flag = false;
		for(int j = 1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j] != 0) flag = false;
		}
	}
	int st = 0;
	if(flag) st = (1 << k) - 1;
	sort(e+1,e+m+1,cmp);
	int ans = 0;
	for(int i = 1;i<=m;i++){
		int A = Find(e[i].u);
		int B = Find(e[i].v);
		if(A != B){
			fa[A] = B;
			ans += e[i].w;
			E[++top] = e[i];
		}
	}
	for(int s = st;s < (1 << k);s++){
		int res = 0,cnt = 0;
		for(int i = 1;i<n;i++)
			ed[i] = E[i];
		top = n - 1;
		for(int i = 0;i<k;i++){
			if((s >> i) & 1){
				cnt++;
				res += c[i + 1];
				for(int j = 1;j<=n;j++){
					ed[++top] = {n + i + 1,j,a[i+1][j]};
				}
			}
		}
		sort(ed+1,ed+top+1,cmp);
		for(int i = 1;i<=n+k;i++)
			fa[i] = i;
		for(int i = 1;i<=top;i++){
			int A = Find(ed[i].u);
			int B = Find(ed[i].v);
			if(A != B){
				fa[A] = B;
				res += ed[i].w;
			}
		}
		ans = min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}
