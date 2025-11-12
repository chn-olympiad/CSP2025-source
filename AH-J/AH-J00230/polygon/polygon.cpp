#include<bits/stdc++.h>
#define int long long
#define N 5005
using namespace std;
const int MOD=998244353;
int n,a[N],cnt,vis[N],ret;
void dfs(int sum,int last,int goal){
	if(sum>a[goal]) ret=(ret+1)%MOD;
	for(int j=last+1;j<goal;j++){
		if(!vis[j]){
			vis[j]=1;
			dfs(sum+a[j],j,goal);
			vis[j]=0;
		}
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		memset(vis,0,sizeof(vis));
		vis[0]=1;
		ret=0;
		dfs(0,0,i);
		cnt=(cnt+ret)%MOD;
	}
	cout<<cnt;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
