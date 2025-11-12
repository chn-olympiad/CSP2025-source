#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,MAX;
int ans;
int a[5005];
void dfs(const int& k,const int& num,const int& sum,const int& maxa){
	if(k==n+1){
		if(n>=3&&sum>maxa*2) ans++,ans%=mod;
		return;
	}
	dfs(k+1,num,sum,maxa);
	dfs(k+1,num+1,sum+a[k],max(maxa,a[k]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),MAX=max(MAX,a[i]);
	if(MAX==1){
		long long jc[5005]={1,1};
		long long sum=1;
		for(int i=2;i<=n;i++) sum*=i,jc[i]=sum;
		for(int i=3;i<=n;i++){
			int up=jc[i],down=jc[n]/jc[n-i];
			ans+=down/up,ans%=mod;
		}
	}
	else dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}
