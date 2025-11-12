#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
long long ans;
int a[20000];
void dfs(int cnt,int mx,int sum,int now){
	if(now>n){
		ans=(ans+1)%mod;
	}
	return;
}
int main(){
	//freopen("seat.in","r",stdin)
    //freopen("seat.out","w",stdout)
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
}
