#include<bits/stdc++.h>
using namespace std;

const int N = 1e9+5;

int n;	//原有城市 
int m;	//道路数量 
int k;	//准备进行城镇化 
int mp[N][N];	//第i条道路连接的两座城市及维修费用 
int con[n][N]; 
long long dp[N];

int inline read(){
	int x=0, f=1;
	char ch = getchar();
	if(ch<'0' || ch>'9'){
		if(ch == '-'){
			f = -1;
			ch = getchar();
		}
	}
	if(ch>='0' && ch <='9'){
		x = x*10 + ch -'0';
		ch = getchar();
	}
	return x*f;
}

//int fa(int i){
//	if(fa[i] == i)	return i;
//	if(fa[fa[i]] == i)  
//}

int main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read();
	m = read();
	k = read();
	for(int i=1; i<=m; i++){
		int w, u, v;
		mp[w][u] = v;
		mp[u][w] = v;
	}
	
	if(k == 0){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				
			}	
		}
	}
	
	
	
	return 0;
}
