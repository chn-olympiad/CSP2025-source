#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int x,int maxx,int sum){
	if(x>n){
		if(maxx*2<sum){
			ans++;
		}
		return;
	}
	dfs(x+1,max(maxx,a[x]),sum+a[x]);
	dfs(x+1,maxx,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1,0,0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
