#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 25;
const int M = 1e6 + 5;
typedef long long ll;
namespace subtask1{
	int c[15];
	pair<int,int> a[N];
	
	struct node{
		int u,v,w;
		friend bool operator < (const node x,const node y){
			return x.w < y.w;
		}
	}tree[15 * N],b[M];
	int n,m,k,cnt = 0;
	ll res = 4e18;
	
	int f[N];
	int t[2050][N];
	void init(){
		for (int i = 1;i <= n + k;++i) f[i] = i;
	} int find(int x){
		if (f[x] == x) return x;
		return f[x] = find(f[x]);
	} void merge(int x,int y){
		int fx = find(x),fy = find(y);
		if (fx == fy) return ;
		f[fx] = fy; return ;
	}
	void Merge(int x,int y){
		int p = 1,q = 1,cntxy = 0;
		init();
		while (t[x][p] != 0 || t[y][q] != 0){
		    int pos = 0;
			if (t[x][p] == 0) pos = t[y][q],++q;
			else if (t[y][q] == 0) pos = t[x][p],++p;
			else if (tree[t[x][p]] < tree[t[y][q]]) pos = t[x][p],++p;
			else pos = t[y][q],++q;
			int u = tree[pos].u,v = tree[pos].v;
			if (find(u) == find(v)) continue;
			merge(u,v);
			t[x | y][++cntxy] = pos;
		}
	}
	void main(){
		scanf("%d%d%d",&n,&m,&k);
		for (int i = 1;i <= m;++i){
			scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
		} 
		
		init();
		sort(b + 1,b + m + 1);
		for (int i = 1;i <= m;++i){
			int u = b[i].u,v = b[i].v;
			if (find(u) == find(v)) continue;
			merge(u,v);
			tree[++cnt] = b[i];
			t[1][cnt] = cnt;
		}
		
		for (int i = 1;i <= k;++i){
			scanf("%d",&c[i]);
			for (int j = 1;j <= n;++j){
				int val; scanf("%d",&val);
				a[j].first = val,a[j].second = j;
			}
			sort(a + 1,a + n + 1);
			for (int j = 1;j <= n;++j){
			    tree[++cnt] = (node){n + i,a[j].second,a[j].first};
			    t[1 << i][j] = cnt;
			} 
		}
		
		for (int i = 1;i < (1 << (k + 1));++i){
			int p = 0; ll sum = 0;
			for (int j = 0;j <= k;++j)
			    if (i >> j & 1) sum += c[j],p = j;
			    
			for (int j = 1;j <= n + k;++j)
			    sum += tree[t[i][j]].w;
			res = min(res,sum);
			
			for (int j = p + 1;j <= k;++j)
				Merge(i,1 << j);
			//cout << i << " " << sum << endl;
		}
		printf("%lld\n",res);
		return ;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	subtask1 :: main();
	return 0;	
}
