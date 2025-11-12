#include <iostream>
#include <algorithm>
using namespace std;
//the famous problem--steiner tree!

struct Edge{
	int u,v,w;
};

Edge edges[1000005];
int n,m,k,f[10015],c[15];
int ext_ml[15][10005];
Edge treg[110005];

int find(int x){return f[x] == x ? x : f[x] = find(f[x]);}

bool operator < (Edge a,Edge b){
	return a.w < b.w;
};

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
	//we first find origin MST.
	sort(edges + 1,edges + m + 1);
	//now get Steiner.
	for(int i = 1;i <= k; i++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++) cin >> ext_ml[i][j];
	}
	long long res = 9e18;
	for(int st = 0;st < (1 << k); st++){
		long long ans = 0,ccnt = 0;
		for(int i = 1;i <= k; i++) if(st >> (i - 1) && 1){
			ans += c[i];
			for(int j = 1;j <= n; j++) treg[++ccnt] = {j,i+n,ext_ml[i][j]};
		}
		sort(treg + 1,treg + ccnt + 1);
		treg[ccnt+1] = edges[m+1] = {0,0,1000000000};
		for(int i = 1;i <= k + n; i++) f[i] = i;
		int l1 = 1,l2 = 1;
		while(l1 <= m || l2 <= ccnt){
			Edge s;
			if(treg[l2] < edges[l1]) s = treg[l2++];
			else s = edges[l1++];
			int u = find(s.u),v = find(s.v);
			if(u == v) continue;
			f[u] = v;
			ans += s.w;
		}
		res = min(res,ans);
	}
	cout << res << endl;
		
	
	return 0;
}