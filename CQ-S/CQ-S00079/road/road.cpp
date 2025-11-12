#include<iostream>
#include<algorithm>
#define int long long 
using namespace std;
const int N=1e4+100,N2=1e6+1e5+100;
struct node{
	int u,w,p;
}edge[N2];
int fa[N],fl[N],fmul[N],mul,idx,n,m,k,nums,ans;
bool cmp(node a, node b){
	return a.p < b.p;
}
int find(int x){
	if (fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
signed main(){
	//freopen(".//road//road1.in","r",stdin);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m >> k;
	for (int i=1;i<=n+k+k;++i) fa[i] = i;
	for (int i=1;i<=m;++i){
		cin >> edge[++idx].u >> edge[idx].w >> edge[idx].p; 
	}
	for (int i=1, q;i<=k;++i){
		cin >> q;
		fmul[i+n] = -q;
		for (int j=1;j<=n;++j){
			cin >> edge[++idx].p;
			edge[idx].p += q;
			edge[idx].u = i+n;
			edge[idx].w = j;
		}
	}
	sort(1+edge,1+edge+idx,cmp);
	//for (int i=1;i<=idx;++i){
		//cout << edge[i].u << ' ' << edge[i].w << ' ' << edge[i].p << endl;
	//}
	for (int i=1;i<=idx;++i){
		int u=edge[i].u, w=edge[i].w, p=edge[i].p;
		if (find(u) == find(w)) continue;
		cout << edge[i].u << ' ' << edge[i].w << ' ' << edge[i].p << endl;
		//if (u > n+k && fl[u] && w <= n)nums++;
		
		fa[find(u)] = find(w);
		
		ans += p;
		if (u > n+k) mul++;
		if (find(u) <= n && find(u) != w){
			//cout << u << ' '<< w << endl;
			nums++; 
		}
		if (u <= n || w <= n || fl[find(u)]) fl[find(u)]=1;
		if (nums >= n-1) break;
	}
	cout << ans;
}
