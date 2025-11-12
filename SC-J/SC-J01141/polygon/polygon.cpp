#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n,a[N],pre[N];
long long ans;
void dfs(int i,int c,int maxn,int cnt){
	if(i>n){
		if(cnt>=3&&maxn*2<c) ans=(ans+1)%mod;
		return;
	}
	dfs(i+1,c,maxn,cnt);
	dfs(i+1,c+a[i],a[i],cnt+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[1]==1&&a[n]==1){
		for(int i=3;i<=n;i++){
			long long t=1;
			for(int j=n-i+1;j<=n;j++){
				t*=j;
				t%=mod;
			}for(int j=1;j<=i;j++){
				t/=j;
			}
			ans+=t;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans/2;
	return 0;
}