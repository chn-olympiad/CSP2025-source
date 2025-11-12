#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0;
bool vis[5005];
void dfs(long long x,long long cnt,long long maxl,long long last){
	if(x>=3&&x<=n){
		if(cnt>2*maxl){
			ans++;
			ans=ans%998244353;
		}
	}
	if(x>=n){
		return ;
	}
	for(int i=last;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(x+1,cnt+a[i],max(maxl,a[i]),i+1);
			vis[i]=false;
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
	dfs(0,0,-1e9,1);
	cout<<ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
