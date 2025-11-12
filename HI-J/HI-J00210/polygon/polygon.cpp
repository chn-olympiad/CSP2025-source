#include<bits/stdc++.h>
using namespace std;
int n,a[5010],cnt;
void dfs(int x,int sum,int mx,bool c){
	if(x>2&&sum>2*mx&&c) cnt++,cnt%=998244353;
	if(x==n) return;
	dfs(x+1,sum+a[x+1],max(mx,a[x+1]),1);
	dfs(x+1,sum,mx,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(0,0,0,0);
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
