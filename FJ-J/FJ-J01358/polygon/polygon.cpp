#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
int n,a[N],ans,num[N];
bool t=1;
void dfs(int k,int sum,int MAX){
	if(k>n){
		if(sum>MAX*2)ans=(ans+1)%mod;
		return;
	}
	dfs(k+1,sum+a[k],max(MAX,a[k]));
	dfs(k+1,sum,MAX);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1)t=0;
	}
	sort(a+1,a+n+1);
	if(t){
		num[0]=1;
		for(int i=1;i<=n;i++)num[i]=num[i-1]*i;
		for(int i=3;i<=n;i++)ans=(ans+num[n]/(num[i]*num[n-i]))%mod; 
	}
	else dfs(1,0,0);
	printf("%d",ans%mod);
}
