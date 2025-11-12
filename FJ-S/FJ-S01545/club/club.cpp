#include<bits/stdc++.h>
#define N 100050
using namespace std;
int a[N],b[N],c[N],maxn,t,n;
void dfs(int x,int ca,int cb,int cc,int ans){
//	printf("%d;%d;%d;%d;%d\n",x,ca,cb,cc,ans);
	if(x>n){
		maxn=max(maxn,ans);
		return ;
	}
	if(ca+1<=n/2)dfs(x+1,ca+1,cb,cc,ans+a[x]);
	if(cb+1<=n/2)dfs(x+1,ca,cb+1,cc,ans+b[x]);
	if(cc+1<=n/2)dfs(x+1,ca,cb,cc+1,ans+c[x]);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		maxn=0;
		for(int i=1;i<=n;i++)scanf("%d%d%d",a+i,b+i,c+i);
		dfs(1,0,0,0,0);
		printf("%d\n",maxn);
	}
	return 0;
}
