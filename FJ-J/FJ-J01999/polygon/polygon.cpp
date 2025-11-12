#include<bits/stdc++.h>
#define ll long long
#define MAXN 5005
using namespace std;
const int mod=998244353;
int n,a[MAXN];
ll ans=0;
void dfs(int x,int sum,int ma,int num){
	if(x==n+1){
		if(sum>ma*2&&num>=3) ans=(ans+1)%mod;
		return;
	}
	dfs(x+1,sum+a[x],max(ma,a[x]),num+1);
	dfs(x+1,sum,ma,num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans%mod;
	return 0;
}
