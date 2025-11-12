#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll n,a[5005],sum,maxn,ans;
void dfs(ll cur,ll mx,ll sm,ll cnt,bool f){
	if(cnt>=3&&sm>mx*2&&f==0){
		(ans+=1)%=MOD;
	}
	if(cur==n+1){
		return ;
	}
	dfs(cur+1,max(mx,a[cur]),sm+a[cur],cnt+1,0);
	dfs(cur+1,mx,sm,cnt,1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if(sum>maxn*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(maxn==1){
		for(int i=3;i<=n;i++){
			ll cum=1;
			for(int j=n;j>=n-i+1;j--){
				(cum*=j)%=MOD;
			}
			for(int j=i;j>=1;j--){
				(cum/=j)%=MOD;
			}
			(ans+=cum)%=MOD;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0,0);
	cout<<ans;
    return 0;
}
