#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353 ;
int n,a[5010],s[5010],st[5010],d[5010],ans;
void dfs(int x,int cnt,int mx,int sum){
	if(x==n+1){
		if(cnt>mx*2&&sum>=3){
			ans++;
			ans%=mod;
		}
		return ;
	}
	dfs(x+1,cnt+a[x],max(mx,a[x]),sum+1);
	if(n-x+sum>=3)dfs(x+1,cnt,mx,sum);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		d[i]=max(d[i-1],a[i]);
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
} 
