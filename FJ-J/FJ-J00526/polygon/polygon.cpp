#include<bits/stdc++.h>
using namespace std;

// freopen()freopen()freopen()freopen()freopen()freopen()

int n;long long ans;
int a[5500];
//bool f[300];

void dfs(int u,int maxn,int sum,int sl){
	if(sum > maxn*2 && sl >= 3) ans = (ans + 1) % 998244353;
	/*if(sum > maxn*2 && sl >= 3){
		for(int i = 1;i<=300;i++) if(f[i]) cout<<i<<' ';
		printf("         u£º%d    maxn:%d   sum:%d   sl:%d\n",u,maxn,sum,sl);
	}*/
	
	
	if(u > n) return;
	//È¡ 
	//f[u] = 1;
	if(maxn < a[u]) dfs(u+1,a[u],sum + a[u],sl+1);
	else dfs(u+1,maxn,sum + a[u],sl+1);
	
	
	//f[u] = 0;
	dfs(u+1,maxn,sum,sl);
	return;
}	

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i];
	dfs(1,-1,0,0);
	cout<<ans-2;
	return 0;
}

/*
5
2 2 3 8 10
*/
