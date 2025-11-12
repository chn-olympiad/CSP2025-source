#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,a[5005],ans,x[50005];
void dfs(ll sum,ll k,ll pos,ll l,ll len){
	if(sum>k&&len>=3){
		ans++;
		ans%=mod;
	}
	for(int i=l;i<pos;i++){
		x[len]=a[i];
		dfs(sum+a[i],k,pos,i+1,len+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(0,a[i],i,1,1);
	}
	printf("%lld",ans);
	return 0;
}
/*2025.11.1CSP-J游记 
8.35 卷子发下来了 
8.40 T1期望100pts 
8.50 T2期望100pts
10.40 上厕所 
10.46 T3期望60pts
11.29 T4期望40pts
11.33 检查T1T2 
*/ 
