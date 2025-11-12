#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005],vis[5005],n;
long long ans=0;
void dfs(int pos,int num,int maxn,int cnt){
	if(num>2*maxn && cnt>2) ans=(ans+1)%mod;
	for(int i=pos+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i,num+a[i],max(maxn,a[i]),cnt+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool flag=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) flag=0;
	}
	if(flag){
		printf("%lld",(long long)(n-2)*(n-1)/2);
		return 0;
	}
	dfs(0,0,0,0);
	printf("%lld",ans);
	return 0;
}

