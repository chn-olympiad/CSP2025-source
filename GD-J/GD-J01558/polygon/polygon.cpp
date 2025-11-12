#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],step=0;
bool f[5005];
long long ans;
const long long mod=998244353;
void dfs(int i,int sum,int maxi){
	if(step>=3&&sum>maxi*2){
		ans=(ans+1)%mod;
	}
	for(;i<=n;i++){
		if(f[i]==true){
			b[++step]=a[i],f[i]=false;
			dfs(i+1,sum+a[i],max(maxi,a[i]));
			b[step]=0,step--,f[i]=true;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(f,true,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
