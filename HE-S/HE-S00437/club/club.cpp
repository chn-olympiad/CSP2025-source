#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[100010][10];
void dfs(int x,int step,int an,int bn,int cn){
	if (step==n+1&&an<=n/2&&bn<=n/2&&cn<=n/2){
	ans=max(ans,x);
	return;
	}
	dfs(x+a[step][1],step+1,an+1,bn,cn);
	dfs(x+a[step][2],step+1,an,bn+1,cn);
	dfs(x+a[step][3],step+1,an,bn,cn+1);
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i=1;i<=t;i++){
	cin >> n;
	for (int j=1;j<=n;j++){
	cin >> a[j][1] >> a[j][2] >> a[j][3];
	}
	ans=0;
	dfs(0,1,0,0,0);
	cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
