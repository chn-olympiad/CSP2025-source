#include <bits/stdc++.h>

using namespace std;

int MOD=998244353;
int a[5005],vis[5005];
int b,n;

void dfs(int k,int ans,int n_max){//
	if(k>n){
		return;
	}
	if(k>2 && ans > n_max * 2){
		cout<<ans<<" "<<n_max<<endl;
		b++;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			vis[i]==1;
			dfs(k+1,ans+a[i],max(n_max,a[i]));
			vis[i]==0;
		}
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool isA=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			isA=0;
		}
	}
	if(isA){
		cout<<n-3;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==3){
		if(a[0]+a[1]>a[2] && a[0]+a[2]>a[1] && a[1]+a[2]>a[0]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	//dfs(0,0,0);
	//cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
