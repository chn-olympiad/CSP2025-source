#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n, m, T, ans, k, a[N][4], t[4], b[N], c[N], minn;
vector<pair<int, int>> e[N];
int read(){
	int s=0, f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void dfs(int u, int f){
	if(f==1&&u!=1) return;
	for(int i=0; i<e[u].size(); i++){
		int v=e[u][i].first, w=e[u][i].second;
		if(u==v) continue;
		dfs(v, u);
		ans+=w;
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1; i<=m; i++){
		int u=read(), v=read(), w=read();
		e[u].push_back(make_pair(v, w));
		e[v].push_back(make_pair(u, w));
	}
	for(int i=1; i<=k; i++){
		int p=read();
		p=p;
		for(int j=1; j<=m; j++){
			int x=read();
			e[i].push_back(make_pair(j, x));
			e[j].push_back(make_pair(i, x));
		}
	}
	dfs(1, 1);
	cout<<ans<<endl;
	return 0;
}
