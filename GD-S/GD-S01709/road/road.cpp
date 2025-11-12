#include<cstdio>
#include<algorithm>
#define N 10050
#define ll long long
int n, m, num;
int k, h[N], v[15], s[15][N];
int f[N];//²¢²é¼¯ 
ll ans;
struct Bian{
	int a, b, c, n;
}g[N*100<<1];
struct Kru{
	int a, b, c;
}d[N*100<<1];
void cun(int a, int b, int c){
	g[++k].a=a, g[k].b=b, g[k].c=c;
	g[k].n=h[a], h[a]=k;
}
bool cmp(Kru x, Kru y){
	return x.c < y.c;
}
int as(int x){
	if(x == f[x]){
		return x;
	}
	return f[x] = as(f[x]);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int i, j, a, b, c, fa, fb;
	scanf("%d%d%d", &n, &m, &num);
	for(i=1; i<=m; i++){
		scanf("%d%d%d", &a, &b, &c);
		cun(a, b, c), cun(b, a, c);
	}
	for(i=1; i<=num; i++){
		scanf("%d", v+i);
		for(j=1; j<=n; j++) scanf("%d", &s[i][j]);
		if(!v[i]){
			for(j=1; j<=n; j++){
				if(!s[i][j]){
					cun(n+i, j, 0), cun(j, n+i, 0);
				}
			}
		}
	}
	for(i=1; i<=k; i++){
		d[i].a=g[i].a, d[i].b=g[i].b, d[i].c=g[i].c;
	}
	std::sort(d+1, d+k+1, cmp);
	
	for(i=1; i<=n+num; i++) f[i] = i;
	for(i=1; i<=k; i+=2){
		a = d[i].a, b = d[i].b, c = d[i].c;
		fa = as(a), fb = as(b);
		if(fa != fb){
			ans+=c, f[b] = fa;
		}
	} 
	printf("%lld\n", ans);
	fclose(stdin), fclose(stdout);
	return 0;
}
