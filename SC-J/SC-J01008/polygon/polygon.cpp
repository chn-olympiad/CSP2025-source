#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int Mod=998244353;
int n,a[N],ans;
void dfs(int x,int maxn,int sum){
	if(x==n+1){
		if(sum>2*maxn){
			ans++;
			ans%=Mod;
		} 
		return ;
	}
	dfs(x+1,max(maxn,a[x]),sum+a[x]);
	dfs(x+1,maxn,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	dfs(1,INT_MIN,0); 
	printf("%d",ans);
	return 0;
}