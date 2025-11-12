#include<bits/stdc++.h>//dfs
using namespace std;
int a[5005];int n;
const int mod=998244353;
int dfs(int x,int ans,int cnt,bool flag){
	if(ans*2<cnt){
 		flag=1;
	}else{
		flag=0;
	}
	if(x==n+1){
		return flag;
 	}
 	if(ans*2<cnt){
 		flag=1;
	}else{
		flag=0;
	}
	return (dfs(x+1,max(ans,a[x]),cnt+a[x],flag)%mod+dfs(x+1,ans,cnt,flag)%mod)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	cout<<dfs(1,0,0,0)%mod;
	return 0;
} 
