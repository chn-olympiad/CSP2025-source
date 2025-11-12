#include<bits/stdc++.h>
using namespace std;
const int mod = 98244353;
const int maxn = 5004;
int a[maxn],ans;
void dfs(int x,int sum,int &n,int m,int last){
	if(m>=3 and sum>a[x]*2)
		ans++,ans%=mod;
	if(n-x<3-m) return;
	for(int i=x+1;i<=n;i++)
		dfs(i,sum+a[i],n,m+1,x);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(0,0,n,0,0);
	cout<<ans<<"\n";
	return 0;
}
