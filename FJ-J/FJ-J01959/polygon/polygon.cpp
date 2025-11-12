#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5002],cnt=0,n;
void dfs(int sum,int mx,int k){
	if(k==n+1){
		if(sum>mx*2)cnt=(cnt+1)%998244353;
		return ;
	}
	dfs(sum+a[k],max(mx,a[k]),k+1);
	dfs(sum,mx,k+1);
	return ;
}
void solve1(){
	if(n<3||a[1]+a[2]+a[3]<=2*max(a[1],max(a[2],a[3])))cout<<0;
	else cout<<1;
}
void solve2(){
	dfs(0,0,1);
	cout<<cnt;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=3)solve1();
	else solve2();
	return 0;
} 
