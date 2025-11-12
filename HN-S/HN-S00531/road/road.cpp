//n<=1e4 m<=1e6 k<=10
//感觉可以用二分答案 先暴力吧 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+5, M = 1e6+5;
struct road{ //城市u v 被道路w所链接 
	int u,v,w;
}a[N];
int vis[N];//度 
int n,m,k;//城市 路 装修城市个数 
int c[N][6]; //c[][1]乡镇装修费用 c[][2~6]城市链接城市的费用(1~n);   乡镇是独立的 
bool city_if(){
	for(int i = 1;i <= n;i++){
		if(!vis[i]) return false;
	}
	return true;
}
int mins = 0x7f7f7f7f;
void dfs(int d,int s){
	if(city_if()){
		mins = min(mins,s);
		return;
	}else if(d > m) return;
	vis[a[d].u]++,vis[a[d].v]++;
	dfs(d+1,s+a[d].w);
	vis[a[d].u]--,vis[a[d].v]--;
	dfs(d+1,s);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//输入 
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i = 1;i <= k;i++) cin>>c[i][1]>>c[i][2]>>c[i][3]>>c[i][4]>>c[i][5];
	
	//我k 好复杂 
	//特殊A c[][] = 0
	dfs(1,0);
	cout<<mins;
	return 0;
}

