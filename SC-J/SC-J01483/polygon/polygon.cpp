#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353;
int n,x,ma=INT_MIN;
int ans;
vector<int> a(5010);
vector<vector<int> > f(5010,vector<int>(2510));
int fun(int t,int p){
	p=min(p,t-p);
	if(f[t][p]) return f[t][p];
	if(p==1) f[t][p]=t;
	else if(p==0) f[t][p]=1;
	else f[t][p]=fun(t,p-1)*(t+1-p)/p%M;
	return f[t][p];
}
void dfs(int k,int cnt,int start,int sum){
	if(start*2-2<sum&&k>=3) ans=(ans+cnt)%M;
	if(start>ma) return;
	for(int i=start;i<=ma;i++){
		if(!a[i]) continue;
		for(int j=1;j<=a[i];j++){
			dfs(k+j,cnt*fun(a[i],j)%M,i+1,sum+i*j);
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	f[1][1]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x),a[x]++,ma=max(ma,x);
	dfs(0,1,1,0);
	printf("%d",ans);
	return 0;
}