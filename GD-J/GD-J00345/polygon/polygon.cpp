#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,a[5005],ans;
void dfs(ll x,ll ai,ll len,ll maxl){
	if(x>n) return ;
	if(len>2*maxl) ans++;
	for(ll i=1;i<=n;i++){
		if(i>ai) dfs(x+1,i,len+a[i],max(maxl,a[i]));
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(ll i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(ll i=1;i<=n;i++){
		dfs(1,i,a[i],a[i]);	
	}
	cout<<ans;
	/*
	5
	1 2 3 4 5
	*/
	return 0;
}
