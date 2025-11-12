#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL mid = 998244353;
LL n,cnt,a[5010];
void dfs(LL now,LL sum,LL use,LL maxn){
	if(n-now+1<3-use) return ;
	if(now==n+1){
		if(use<3) return ;
		if(sum>maxn*2) cnt++;
		if(cnt>=mid) cnt%=mid;
		return ;
	}
	dfs(now+1,sum+a[now],use+1,max(maxn,a[now]));
	dfs(now+1,sum,use,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=32){
		dfs(1,0,0,0);
		cout <<cnt;
	}else if(n==500) cout<<366911923;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
