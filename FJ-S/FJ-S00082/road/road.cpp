#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
const int M = 1e6+10;

int n,m,k;
int t;
int fa[N];
int ans;
struct edge{
	int u,v,w,f;
}a[M];
int c[N];
int isu[N];
int ms[N];

bool cmp(edge e1,edge e2){
	return e1.w<e2.w;
}

int find(int x){
	return x == fa[x]? x:fa[x] = find(fa[x]);
}

void merge(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx!=fy){
		fa[fx] = fy;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i<=n;i++){
		fa[i] = i;
	}
	for(int i = 1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		++t;
		a[t].u = x;
		a[t].v = y;
		a[t].w = z;
		a[t].f = 0;
	}
	
	for(int i = 1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j = 1;j<=n;j++){
			int l;
			scanf("%d",&l);
			++t;
			a[t].u = i;
			a[t].v = j;
			a[t].w = l+c[i];
			a[t].f = 1;
			if(i == j){
				ms[i] = a[t].w-c[i];
			}
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i = 1;i<=t;i++){
		if(find(a[i].u) == find(a[i].v)){
			continue;
		}
		ans+=a[i].w;
        if(a[i].f == 1){
        	isu[a[i].u]++;
		}
		merge(a[i].u,a[i].v);
	}
	for(int i = 1;i<=k;i++){
		if(isu[i]){
			ans-=(isu[i]-1)*c[i];
			ans+=ms[i];
		}
	}
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
