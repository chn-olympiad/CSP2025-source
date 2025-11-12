#include<bits/stdc++.h>
using namespace std;
int n,mg[10000];
long long ans;
void dp(int xz,long long h,int mx,int rh){
	if(mx*2<h&&rh>2) ans++,ans%=998244353;
	for(int i=xz;i<=n;i++)
		dp(i+1,h+mg[i],mg[i],rh+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&mg[i]);
	sort(mg+1,mg+n+1);
	dp(1,0,0,0);
	printf("%lld",ans);
	return 0;
}
