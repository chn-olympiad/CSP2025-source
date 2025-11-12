#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge{
	int u, v, w;
} e[1145141];
bool case1,caseA,case2;//case1:k = 0,caseA:A,case2:k <= 5;
int c[11];
int a[11][11451];
struct Union_Find_Set{
	int f[11451];
	void init(){
		for(int i = 1;i<=10100;i++){
			f[i] = i;
		}
	}
	int find(int u){
		if(f[u] == u){
			return u;
		}
		f[u] = find(f[u]);
		return f[u];
	}
	void merge(int u,int v){
		u = find(u),v = find(v);
		if(u == v){
			return ;
		}
		f[u] = v;
		return ;
	}
}ufs;
bool cmp(edge a,edge b){
	return a.w < b.w;
}
void solve1(){
	ufs.init();
	int ans = 0;
	sort(e+1,e+m+1,cmp);
	//for(int i = 1;i<=m;i++){
	//	cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
	//}
	int cnt = 0;
	for(int i = 1;i<=m;i++){
		if(cnt == n){
			break;
		}
		if(ufs.find(e[i].u) == ufs.find(e[i].v)){
			continue;
		}
		ans += e[i].w;
		ufs.merge(e[i].u,e[i].v);
		cnt++;
		//cout<<e[i].w<<' ';
	}
	cout<<ans;
	return ;
}
void solveA(){
	ufs.init();
	for(int i = 1;i<=k;i++){
		for(int j = 1;j<=n;j++){
			m++;
			e[m] = (edge){n+i,j,a[i][j]};
		}
	}
	n += k;
	int ans = 0;
	sort(e+1,e+m+1,cmp);
	for(int i = 1;i<=m;i++){
		//if(cnt == n){
		//	break;
		//}
		if(ufs.find(e[i].u) == ufs.find(e[i].v)){
			continue;
		}
		ans += e[i].w;
		ufs.merge(e[i].u,e[i].v);
		//cnt++;
	}
	cout<<ans;
	return ;
}
edge tmpe[1145141];
void solve2(){
	int ans = INT_MAX,cur = 0,tmpm = m,tmpn = n;
	for(int i = 0;i<(1<<k);i++){
		cur = 0;
		tmpm = m,tmpn = n;
		ufs.init();
		for(int i = 1;i<=m;i++){
			tmpe[i] = e[i];
		}
		for(int j = 0;j<=k;j++){
			if((i>>j)&1){
				cur += c[j+1];
				tmpn++;
				for(int K = 1;K<=n;K++){
					tmpm++;
					tmpe[tmpm] = (edge){tmpn,K,a[j+1][K]};
				}
			}
		}
		sort(tmpe+1,tmpe+tmpm+1,cmp);
		for(int i = 1;i<=tmpm;i++){
			//if(cnt == n){
			//	break;
			//}
			if(ufs.find(tmpe[i].u) == ufs.find(tmpe[i].v)){
				continue;
			}
			cur += tmpe[i].w;
			ufs.merge(tmpe[i].u,tmpe[i].v);
			//cnt++;
		}
		ans = min(ans,cur);
	}
	cout<<ans;
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	if(k == 0){
		case1 = 1;
	}else if(k <= 5){
		case2 = 1;
	}
	for(int i = 1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	caseA = 1;
	int minn;
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		if(c[i] != 0){
			caseA = 0;
		}
		minn = INT_MAX;
		for(int j  = 1;j<=n;j++){
			cin>>a[i][j];
			minn = min(minn,a[i][j]);
		}
		if(minn != 0){
			caseA = 0;
		}
	}
	if(case1){
		solve1();
	}else if(caseA){
		solveA();
	}else{
		solve2();
	}
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
 * */
