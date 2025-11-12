#include<bits/stdc++.h>
using namespace std;
#define N 5000
#define ll unsigned long long
int n,m;
int a[N],ans;
int choice[N];
int f[N][N];
inline int sum_of(int i,int j){
	return a[j]-a[i-1];
}
inline int max_of(int i,int j){
	return a[j];
}
void init(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}
void dfs(int x,int y,int l,int s=0,int mx=0){
	if(x==l){
		if(s>mx*2){
			ans++;
			return;
		}
	}
	for(int i=y+1;i<=n;i++){
		choice[x]=a[y];
		dfs(x+1,i,l,s+a[y],a[y]);
	}
}
void collect(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
}
void work(){
	for(int l=3;l<=n;l++){
		for(int s=1;s<=n-l+1;s++){
			choice[1]=s;
			dfs(1,s,l,s,s);
		}
	}
	cout<<ans;
}
void solve(){
	collect();
	work();
}
int main(){
	init();
	solve();
	return 0;
}