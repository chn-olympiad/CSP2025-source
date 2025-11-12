#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1000000],sum,t;
bool cmp(ll x,ll y){
	return x>y;
}
void dfs(ll x,ll y,ll s){
	if(s+a[y]>x*2){
	sum++;
	}
	if(y==n)return;
	for(ll i=y+1;i<=n;i++){
		dfs(x,i,s+a[y]); 
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
	scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++){
		dfs(a[i],i,0);
	}
	printf("%lld",sum);
	return 0;
} 
