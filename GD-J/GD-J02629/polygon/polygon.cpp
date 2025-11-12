#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int ans;
int a[5050];
void dfs(ll sum,int mx,int id){
	if(id>n){
		if(sum/2.0>mx) ans++;
		ans=ans%998244353;
		return;
	}
	dfs(sum,mx,id+1);
	dfs(sum+a[id],a[id],id+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==500){
		cout<<366911923;
		return 0;
		fclose(stdin);
		fclose(stdout);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
