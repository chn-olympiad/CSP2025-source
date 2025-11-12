#include <bits/stdc++.h>
using namespace std;
int n,chs[50005],a[50005],mx=0,ans=0;
bool chsd[50005];
void dfs(int nw,int mx,int sum){
	if(sum>mx*2) ans=(ans+1)%998244353;
	bool flag=1;
	for(int i=nw+1;i<n;i++){
		if(!chsd[i]){
			flag=0;
			chsd[i]=1;
			dfs(i,max(mx,a[i]),sum+a[i]);
			chsd[i]=0;
		}
	}
	if(flag){
		return; 
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(-1,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
