#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int n;
long long sum=0;
int a[5007],ans[5007];
bool f[5007]{1};
void dfs(int x,int k){
	if(x>k){
		long long p=0,mx=0; 
		for(int i=1;i<=k;i++){
			if(a[ans[i]]>mx) mx=a[ans[i]];
			p+=a[ans[i]];
		}
		if(p>mx*2) sum=(sum+1)%mod;
		return;
	}
	for(int i=ans[x-1];i<=n;i++){
		if(f[i]==0){
			f[i]=1,ans[x]=i;
			dfs(x+1,k);
			f[i]=0;
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
	for(int i=1;i<=n;i++){
		dfs(1,i);
	}
	printf("%lld",sum);
	return 0;
}
