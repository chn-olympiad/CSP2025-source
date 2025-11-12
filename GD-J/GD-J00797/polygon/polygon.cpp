#include<bits/stdc++.h>
using namespace std;
int n,a[5001],sum,ans;
const int mod=998244353;
bool flag=true;
void dfs(int dep,int ma){
	if(dep>n){
		if(sum>ma*2){
			ans++;
			ans%=mod;
		}
		return ;
	}
	sum+=a[dep];
	dfs(dep+1,a[dep]);
	sum-=a[dep];
	dfs(dep+1,ma);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=false;
		}
	}
	if(flag){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,a[1]);
	cout<<ans;
	return 0;
}
