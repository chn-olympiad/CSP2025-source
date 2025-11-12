#include<bits/stdc++.h>
using namespace std;
int n,a[5005],dp[5005];
long long ans;
bool b[5005];
void dfs(int x,int o,int s){
	if(x>n)return;
	if(x>=3&&s>a[o-1]*2){
		ans++;
		ans=ans%998244353;
	}
	for(int i=o;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			dfs(x+1,i+1,s+a[i]);
			b[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(0,1,0);
	printf("%d",ans);
	return 0;
}
