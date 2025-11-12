#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],ans;
int dp[5010];//dp[i]表示到i为止最多方案数 
void dfs(int id,int cnt,int mx){
	if (id>n){
		if (cnt>mx*2){
			ans++;
		}
		return ;
	}
	dfs(id+1,a[id]+cnt,max(mx,a[id]));
	dfs(id+1,cnt,mx);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	if (n<3){
		cout << 0;
	}else if(n==3){
		int cnt=0,maxn=-1;
		for (int i=1;i<=n;i++){
			cnt+=a[i];maxn=max(a[i],maxn);
		}
		if (cnt>maxn*2){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		sort(a+1,a+n+1);
		dfs(1,0,0);
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
