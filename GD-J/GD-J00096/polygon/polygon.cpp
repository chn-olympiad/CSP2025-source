#include <bits/stdc++.h>
using namespace std;
int n,a[50005],cnt;
const int MOD=998244353;
bool vis[5005];
void dfs(int x,int y,int sum,int mx) {//x=当前考虑的木棍编号-1 y=未选择的木棍总数  sum=已选择木棍的边长之和 mx=已选木棍中最长的 
	if(y==0) {
		if(sum>(mx<<1)) {
			cnt++;
			cnt%=MOD;
		}
		return ;
	}
	if(x>n) return ;
	vis[x]=1;
	for(int i=x+1;i<=n;i++) {
		//printf("x=%d,y=%d,sum=%d,i=%d\n",x,y,sum,i);
		if(!vis[i]) {
			dfs(i,y-1,sum+a[i],max(mx,a[i]));
		}
	}
	vis[x]=0;
	return ;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int b=3;b<=n;b++) {
		memset(vis,0,sizeof vis);
		dfs(0,b,0,0);
	}
	cout<<cnt%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
