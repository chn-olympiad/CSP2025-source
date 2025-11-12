#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10009],sz[10009],c[19];
pair<int,int>a[19][10009];
struct edge{
	int u,v,w;
	edge(int _u = 0,int _v = 0,int _w = 0):
		u(_u),v(_v),w(_w)
	{}
	bool operator<(const edge &b)const{
		return w < b.w;
	}
}e[1000009];
vector<edge>fe[19];
int top;
int fnd(int x){
	return fa[x] == x ? x : fa[x] = fnd(fa[x]);
} 
bool Union(int x,int y){
	int u = fnd(x),v = fnd(y);
	if(u == v)
		return false;
	if(sz[u] > sz[v])
		swap(u,v);
	fa[u] = v;
	sz[v] += sz[u];
	return true;
}
long long ans = 0;
void srh(int nw,int s,long long sc){
	if(nw > k)
		return;
	srh(nw + 1,s,sc);
	for(int i = 1; i <= n + s + 1; i ++){
		fa[i] = i,sz[i] = 1;
	}
	top ++;
	fe[top].resize(n + s);
	int q = 1;
	unsigned long long p = 0,scnt = 0;
	long long sum = sc + c[nw];
	while(scnt < fe[top].size()){
		if(p == fe[top - 1].size() || (q <= n && fe[top - 1][p].w > a[nw][q].first)){
			if(Union(n + s + 1,a[nw][q].second)){
				fe[top][scnt] = edge(n + s + 1,a[nw][q].second,a[nw][q].first);
				sum += a[nw][q].first;
				scnt ++;
			}
			q ++;
		}
		else{
			if(Union(fe[top - 1][p].u,fe[top - 1][p].v)){
				fe[top][scnt] = fe[top - 1][p];
				sum += fe[top - 1][p].w;
				scnt ++;
			}
			p ++;
		}
	}
	//printf("%lld %lld\n",sc + c[nw],sum);
	ans = min(ans,sum);
	srh(nw + 1,s + 1,sc + c[nw]);
	vector<edge>().swap(fe[top]);
	top --;
}
//I think that it was not necessary to make m too large.
//But i have to accept this.
//Don't worry,fread is here.
char buf[1919810],*p1 = buf,*p2 = buf;
char gc(){
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1919810,stdin),p1 == p2) ? EOF : *p1 ++;
}
void fstin(int &x){
	x = 0;
	char c = gc();
	while(c > '9' || c < '0')
		c = gc();
	while(c >= '0' && c <= '9')
		x = (x << 1) + (x << 3) + (c ^ 48),c = gc();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fstin(n),fstin(m),fstin(k);
	for(int i = 1; i <= m; i ++){
		fstin(e[i].u),fstin(e[i].v),fstin(e[i].w);
	}
	for(int i = 1; i <= k; i ++){
		fstin(c[i]);
		for(int j = 1; j <= n; j ++){
			fstin(a[i][j].first);
			a[i][j].second = j;
		}
		sort(a[i] + 1,a[i] + n + 1);
	}
	sort(e + 1,e + m + 1);
	for(int i = 1; i <= n; i ++){
		fa[i] = i;
		sz[i] = 1;
	}
	top = 1;
	int scnt = 0;
	fe[top].resize(n - 1);
	for(int i = 1; i <= m; i ++){
		if(scnt == n - 1)
			break;
		if(Union(e[i].u,e[i].v)){
			ans += e[i].w;
			fe[1][scnt] = e[i];
			scnt ++;
		}
	}
	srh(1,0,0);
	printf("%lld\n",ans);
	return 0;
}
