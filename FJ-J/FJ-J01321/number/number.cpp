#include<bits/stdc++.h>
using namespace std;
int n,mg[10000];
long long ans;
void dp(int xz,long long h,int rh){
	if(rh>2&&mg[xz-1]*2<h) ans++,ans%=998244353;
	if(rh>2){
		for(int i=xz;i<=n;i++)
			dp(i+1,h+mg[i],3);
	} else {
		for(int i=xz;i<=n;i++)
			dp(i+1,h+mg[i],rh+1);
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&mg[i]);
	sort(mg+1,mg+n+1);
	dp(1,0,0);
	printf("%lld",ans);
	return 0;
}
