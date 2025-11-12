#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5001];
long long ans;
void dfs(int x,int sum,int maxn,int cnt){
	if(sum>maxn*2 && cnt>=3) ans=(ans+1)%mod;
	for(int i=x+1;i<=n;i++){
		dfs(i,sum+a[i],max(maxn,a[i]),cnt+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(i,a[i],a[i],1);
	}
	printf("%lld",ans);
	return 0;
}

