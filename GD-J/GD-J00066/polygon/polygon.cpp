#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,ans,a[5010];
bool use[5010];
bool check(){
	long long x=0,y=0,z=0;
	for(long long i=1;i<=n;i++){
		if(use[i]){
			x++;
			y+=a[i];
			z=max(a[i],z);
		}
	}
	return x>=3&&y>z*2;
}
void dfs(long long pos){
	if(pos>n){
		if(check()){
			ans++;
			ans%=MOD;
		}
		return;
	}
	use[pos]=1;
	dfs(pos+1);
	use[pos]=0;
	dfs(pos+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
