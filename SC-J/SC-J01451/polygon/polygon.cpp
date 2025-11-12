#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=5005;
int n,m,a[N],ans;
bool flag=1;
void dfs(int s,int sum,int mn){
	if(s>n){
		if(sum>mn*2)ans=(ans+1)%mod;
		return ;
	}
	dfs(s+1,sum,mn);
	dfs(s+1,sum+a[s],max(mn,a[s]));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i!=1)flag=0;
	}
	if(flag){
		for(int i=3;i<=n;i++){
			int mel=1;
			for(int j=n;j>=n-i+1;j--){
				mel=mel*j/(n+1-j);
			}
			ans=(mel+ans)%mod;
		}
		cout<<ans;
		return 0;
	}
//	sort(a+1,a+n+1);
//	reverse(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}