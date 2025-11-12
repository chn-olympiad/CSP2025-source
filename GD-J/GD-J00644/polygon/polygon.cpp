#include<bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int a[5007];
long long ans = 0;
int n;
void dfs(int x,int lsum,int Max){
	if(x > n){
		if(lsum > 2*Max) ans++;
		ans %= Mod;
		return ;
	}
	dfs(x+1,lsum,Max);
	dfs(x+1,lsum+a[x],a[x]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout << ans % Mod;
	return 0;
}




/**
这么看来有点无了
估分100+100+40+40，嗯大概就是应该过不了300
最后两题想不到怎么优化力QAQ 
qwq 
**/

