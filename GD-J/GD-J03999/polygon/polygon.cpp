#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,a[5007],b[5007],cnt;
void dfs(ll s,ll mx,ll num){
	if(num>2 && s>mx*2) cnt++;
	for(int i=num; i<=n; i++)
		if(!b[i]){
			b[i]=1;
			dfs(s+a[i],max(mx,a[i]),num+1);
			b[i]=0;
		}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	dfs(0,0,0);
	printf("%lld",cnt);
	return 0;
}
