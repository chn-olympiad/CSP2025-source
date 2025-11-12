#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod=998244353;
ll a[5005],ans,n;

void dfs(ll pos,ll cnt,ll sum){
	if(cnt>=3&&sum>2*a[pos])ans++;
	if(ans>=mod)ans-=mod;
	for(int i=pos+1;i<=n;i++){
		dfs(i,cnt+1,sum+a[i]);
	}
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans;
    return 0;
}

