#include <bits/stdc++.h>
using namespace std;
const int N=5e3+3;
long long n,ans=0,a[N],f[N];
void dfs(long long now,long long num,long long sum){
	if(now==n+1){
		if(num<3)return;
		for(long long i=n;i>=1;i--){
			if(f[i]==1){
				if(sum>a[i]*2)ans++;
				break;
			}
		}
		return;
	}
	f[now]=1;
	dfs(now+1,num+1,sum+a[now]);
	f[now]=0;
	dfs(now+1,num,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans%998244353;
	return 0;
}
