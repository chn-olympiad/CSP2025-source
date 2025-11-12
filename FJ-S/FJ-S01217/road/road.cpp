#include <bits/stdc++.h>
using namespace std;

int rd(){
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	int ret = 0;
	while('0' <= c && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret;
}

int n, m, k;
int c[12];
pair<int,int> A[12][10002];
struct edge{
	int u, v, w;
}e[1000002], the[30002], temp[30002], temp2[30002];
int thes;
edge beifen[12][30002];
int beifens[12];
bool cmp(const edge &a,const edge &b){
	return a.w < b.w;
}
int fa[20002], siz[20002];
int getfa(int pos){
	if(fa[pos] == pos) return pos;
	fa[pos] = getfa(fa[pos]);
	return fa[pos];
}
void merge(int u,int v){
	if(siz[u] < siz[v]) fa[u] = v, siz[v] += siz[u];
	else fa[v] = u, siz[u] += siz[v];
}

long long Ans = 1e18, NOW = 0;
void solve(int pos){
	if(pos > k){
		long long now = NOW;
		for(int i=1;i<=thes;i++) now = now + the[i].w; 
		Ans = min(Ans, now);
		return;
	}
	
	solve(pos + 1);
	
	beifens[pos] = thes;
	for(int i=1;i<=thes;i++) beifen[pos][i] = the[i];
	
	NOW += c[pos];
	for(int i=1;i<=n;i++) {
		temp[i].u = n + pos;
		temp[i].v = A[pos][i].second;
		temp[i].w = A[pos][i].first;
	}
	int I = 1, J = 1, K = 1;
	while(I <= thes && J <= n){
		if(the[I].w < temp[J].w){
			temp2[++K] = the[I];
			I++;
		}
		else {
			temp2[++K] = temp[J];
			J++;
		}
	}
	while(I <= thes) temp2[++K] = the[I], I++;
	while(J <= n) temp2[++K] = temp[J], J++;
	for(int i=1;i<=n+k;i++) fa[i] = i;
	thes = 0;
	for(int i=1;i<=K;i++){
		int fu = getfa(temp2[i].u);
		int fv = getfa(temp2[i].v);
		if(fu == fv) continue;
		the[++thes] = temp2[i];
		merge(fu, fv);
	}
	
	solve(pos + 1);
	
	NOW -= c[pos];
	thes = beifens[pos];
	for(int i=1;i<=thes;i++) the[i] = beifen[pos][i];
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n = rd(), m = rd(), k = rd();
	for(int i=1;i<=m;i++){
		e[i].u = rd(), e[i].v = rd(), e[i].w = rd();
	}
	for(int i=1;i<=k;i++){
		c[i] = rd();
		for(int j=1;j<=n;j++) A[i][j].first = rd(), A[i][j].second = j;
		sort(A[i]+1,A[i]+n+1);
	}
	sort(e+1,e+m+1,cmp);
	
	for(int i=1;i<=n;i++) fa[i] = i, siz[i] = 1;
	for(int i=1;i<=m;i++){
		int fu = getfa(e[i].u);
		int fv = getfa(e[i].v);
		if(fu == fv) continue;
		merge(fu, fv);
		the[++thes] = e[i];
	}
	
	solve(1);
	
	printf("%lld",Ans);
	
	return 0;
}

/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
