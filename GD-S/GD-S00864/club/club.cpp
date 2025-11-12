#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7;
ll t,n,arr[N][4],ans,k;
void dfs(ll x,ll a,ll b,ll c,ll sum){
	if(a>k||b>k||c>k)return;
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(x+1,a+1,b,c,sum+arr[x][1]);
	dfs(x+1,a,b+1,c,sum+arr[x][2]);
	dfs(x+1,a,b,c+1,sum+arr[x][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		k=n/2;
		bool flag=true;
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&arr[i][1],&arr[i][2],&arr[i][3]); 
		}
		ans=0;
		if(n<=12){
			dfs(1,0,0,0,0);
			printf("%lld\n",ans);
		}else printf("0\n");
	}
	return 0;
}
