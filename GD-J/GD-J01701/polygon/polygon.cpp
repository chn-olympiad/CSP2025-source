#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=5090;
int a[N];
int ans;
void dfs(int num,int maxn,int len,int cnt,int u){
	if(cnt==num){
		if(maxn*2<len){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=u;i<=n;i++){
		dfs(num,max(maxn,a[i]),len+a[i],cnt+1,i+1);
		dfs(num,maxn,len,cnt,i+1);
	}
	return ;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0,1);
	}
	printf("%lld",ans/2%998244353);
}
