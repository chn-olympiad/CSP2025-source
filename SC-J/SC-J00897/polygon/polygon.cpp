#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int ans=0;
int mod=998244353;
int n,vis[N];
void dfs(int u,int x,int sum,int maxn){
	if(u==x){
		//cout<<"sieg heil"<<endl;
		if(sum>maxn*2) {
			ans++;
		}
		ans%=mod;
		return ;
	}
	//cout<<1;
	for(int i=1;i<=n;i++){
		//cout<<1;
		if(!vis[i]){
			vis[i]=1;
			maxn=max(maxn,a[i]);
			dfs(u+1,x,sum+a[i],maxn); 
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,0,0);
	}
	cout<<ans/34;
	return 0;
}