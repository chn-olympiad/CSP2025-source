#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[30],o;
long long ans;
void dfs(int num,int p,int sum,int maxx){
	if(p==n+1){
		if(num>=3&&maxx*2<sum){
			ans++;
		//	cout<<num<<" "<<maxx<<" "<<sum 
		}
		return;
	}
	dfs(num,p+1,sum,maxx);
	dfs(num+1,p+1,sum+a[p],max(maxx,a[p]));	
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		o=max(o,a[i]);
	}
	if(o!=1){
		dfs(0,1,0,0);
	}else{
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans%MOD;
			ans*=2;
		} 
		ans=ans-n-(n-1)*n/2;
		ans=(ans+MOD-1)%MOD;
	}
	cout<<ans%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 