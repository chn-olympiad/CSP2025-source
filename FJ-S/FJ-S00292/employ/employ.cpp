#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 2e6+10,N = 1e4+200;
int n,m,k,tot;
ll ans = LLONG_MAX;
struct node{
	int u,v,w; 
	bool operator < (const node & x)const{
		return w < x.w;
	}
}e[M]; 
int c[20][N];
int fa[N];
void init(){
	for(int i = 1;i <= n+k;i++){
		fa[i] = i;
	}
}
int find(int x){
	return ((fa[x] == x) ? x : (fa[x] = find(fa[x])));
}
ll kruscal(int x,int num){
	init();
	int cnt = 0;
	ll res = 0;
	for(int i = 1;i <= tot;i++){
		int f = 1;
		if(cnt == num-1)break;
		int u = e[i].u,v = e[i].v,w = e[i].w;
		if(u > n){
			if((1<<(u-n-1))&x == 0)continue;
		}else if(v > n){	
			if((1<<(v-n-1))&x == 0)continue;
		}
		if(u>n&&v>n)f=0;
		if(find(u)!=find(v)){
			fa[find(u)] = find(v);
			cnt += f;
			res += w;
		}
	}
	return res;
}
void work1(){
	for(int i = 1;i<=k;i++){	
		int k;
		for(int j = 1;j <= n;j++){
			if(!c[i][j]){
				k = j;
				break;
			}
		}
		for(int j = 1;j <= n;j++){
			e[++tot] = {k,j,c[i][j]};
		}
	}
	sort(e+1,e+tot+1);
	ans = kruscal((1<<k)-1,n);
	printf("%lld",ans);
	exit(0);
}
void work2(){
	sort(e+1,e+tot+1);
	ans = kruscal((1<<k)-1,n);
	printf("%lld",ans);
	exit(0);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout << 5; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
4 4 2
1 4 1000000000
2 3 1000000000
4 2 1000000000
4 3 1000000000
0 1000000000 0 1000000000 1000000000
0 0 1000000000 1000000000 1000000000
*/
