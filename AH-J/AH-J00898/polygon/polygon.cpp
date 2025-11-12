#include <bits/stdc++.h>
using namespace std;
int sticks[100010];
int a[100010],b[100010];
int n,r;
long long int ans=0;
void check(){
	int maxn=INT_MIN,sum=0;
	for(int i=1; i<=r; i++) sum+=sticks[a[i]],maxn=max(maxn,sticks[a[i]]);
	if(maxn*2<sum) ans++; 
}
void dfs(int x,int p){
	for(int i=p; i<=n; i++){
		if(b[i]!=0) continue;
		a[x]=i;
		b[x]=1;
		if(x==r) check();
		else dfs(x+1,i+1);
		b[x]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&sticks[i]);
	for(r=3; r<=n; r++) dfs(1,1);
	printf("%lld",ans%998244353);
	return 0;
}
