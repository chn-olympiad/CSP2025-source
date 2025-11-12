#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],maxn,ans;
void dfs(long long x,long long m,long long sum){
	if(x>n){
		if(sum>2*m){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	dfs(x+1,m,sum);
	dfs(x+1,max(a[x],m),sum+a[x]);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		for(int i=3;i<=n;i++){
			ans+=n+1-i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
    if(n<=20){
		dfs(0,0,0);
		cout<<ans/2;
		return 0;
	}
	return 0;
}
