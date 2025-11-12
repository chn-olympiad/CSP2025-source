#include<bits/stdc++.h>
using namespace std;
const int  mod=998244353;
int ans=0;
int n,a[5005];
inline void dfs(int k,int s,int w){
	if(n-k+1+s<3)return;
	if(k==n+1)return;
	if(w>a[k]&&s>=2)ans++,ans%=mod;
	dfs(k+1,s+1,w+a[k]);
	dfs(k+1,s,w);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}
