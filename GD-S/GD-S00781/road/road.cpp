#include<bits/stdc++.h>
using namespace std;
#define int long long
#define accept 0
int n,m,k,c[100];
struct edge{
	int u,v,w;
}e[2000005];
inline bool cmp(edge a,edge b){
	return a.w < b.w;
}
bool vis[200005];
int kru(){
	for(int i =1;i <= n +10;i++){
		vis[i] = 0;
	} 
	int ans = 0;
	vis[1] = 1;
	for(int i =1;i <= m;++i){
		if(vis[e[i].u] == 0 || vis[e[i].v] == 0){
			ans += e[i].w;
			vis[e[i].u] = vis[e[i].v] = 1;
		}
	}
	return ans;
}
int read(){
	int ans = 0;
	char a = getchar();
	while(a <= '9' && a >= '0'){
		ans *= 10;
		ans += a-'0';
		a = getchar();
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//cout << 1;
	n = read();m = read();k = read();
	for(int i =1;i <= m ;++i ){
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	sort(e+1,e+1+m,cmp);
	int st = kru();
	int ans = 0;
	for(int i = 1;i <= k ;++ i){
		cin >> c[i];
		for(int j = 1;j <= n;++j ){
			edge x;
			x.w = read();
			x.u = n+i;
			x.v = j;
			e[++m] = x;
		}
	}
	if(k == 0){
		cout << st;
	}else{
		sort(e+1,e+1+m,cmp);
		st = kru();
		cout << st + ans;
	}
	fclose(stdin);
	fclose(stdout);
	return accept;
}
