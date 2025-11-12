#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,m,k;
//vector<pair<int,int> > a[10001];
int c[15];
int sum,ans=11000000000000;
struct node{
	int u,v,w;
}a[1100005];
int to;
int fa[10100];

bool cmd(node a,node b){
	return a.w <= b.w;
}

int work(int u){
	int ss = 0,i = 1;
	while(u){
		if(u & 1){
			ss += c[i];
		}
		u >>= 1;
		i ++ ;
	} 
	return ss;
} 

int fun(int u){
	int s = 0;
	while(u){
		if(u & 1)s ++ ;
		u >>= 1;
	}
	return s;
}

bool check(int kkk,int u){
	if(u <= n)return 1;
	return ((1<<(u-n-1)) & kkk); 
}

int find(int u){
	if(fa[u] == u)return u;
	return fa[u] = find(fa[u]);
} 

void prim(int u){
	int kk = fun(u),cnt = 0;
//	cout<<kk<<"\n";
	for(int i = 1; i <= to; i ++ ){ 
//		cout<<"这条边是："<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n"; 
//		cout<<check(u,a[i].u)<<" "<< check(u,a[i].v) <<" "<<find(a[i].u)<<" "<<find(a[i].v)<<"\n";
		if(check(u,a[i].u) && check(u,a[i].v) && find(a[i].u) != find(a[i].v)){
//			cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n"; 
			cnt ++ ;
			sum += a[i].w;
			fa[find(a[i].u)] = find(a[i].v);
		}
		if(cnt == n+kk-1)return ;
	}
} 

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i ++ ){
		cin>>a[++to].u>>a[to].v>>a[to].w;
//		e[++to] = {u,v,w};
	}
	for(int i = n+1; i <= n+k; i ++ ){
		cin>>c[i-n];
		for(int j = 1; j <= n; j ++ ){
			int x;
			cin>>x;
			a[++to] = {i,j,x};
		}
	}
	sort(a+1,a+to+1,cmd);
	int ansid = 0;
	for(int i = 0; i < (1 << k); i ++ ){//二进制展开（倒序：...987654321）。 
		for(int _ = 1; _ <= n+k; _ ++ ){
			fa[_] = _;
		}
		sum = work(i);
		if(sum > ans)continue;
//		cout<<sum<<"\n";
//		for(int j = 1; j <= n+k; j ++ ){
//			cout<<fa[j]<<" "<<find(j)<<"\n";
//		}
		prim(i);
		ans = min(ans,sum);
		if(sum < ans){
			ansid = i;
		}
	}
	cout<<ans;
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
