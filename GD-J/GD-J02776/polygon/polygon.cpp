#include<bits/stdc++.h>
using namespace std;
const long long N=5e3+10,mod=998244353;
long long n,a[5001],sum,ans;
void dfs(int x,int y,int z){
	if(x==y-1&&z>=3){
		if(sum>a[y]*2) ans=(ans+1)%mod;
		return;
	}
	for(int i=x+1;i<y;i++){
		sum+=a[i];
		dfs(i,y,z+1);
		sum-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum=a[i];
		dfs(0,i,0);
	}
	cout<<ans%mod;
	return 0;
}
