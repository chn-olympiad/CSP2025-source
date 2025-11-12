#include<iostream>
#include<stdio.h>
#define mod 998244353
using namespace std;
int a[100005];
bool vis[1000005];
int h;
int ans;
int n;
void pr(){
	int maxn=-15;
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			maxn=max(maxn,a[i]);
			sum+=a[i];
		}
	}
	if(sum>maxn*2){
		ans++;
		ans%=mod;
	}
}
void dfs(int x,int u){
	if(x==h+1){
		pr();
		return;
	}
	for(int i=u+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		h=i;
		dfs(1,0);
	}
	cout<<ans;
	return 0;
}