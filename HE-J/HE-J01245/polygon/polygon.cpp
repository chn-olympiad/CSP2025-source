#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,sum,MAX;
int a[5005];
long long ans=0;
void dfs(int dep,int s,int m,int p)
{
	if(2*m>=sum) return;
	if(dep>n) {
		if(s>2*m) ans++;
		return;
	}
	for(int i=p+1;i<=n;i++) {
		dfs(dep+1,s+a[i],max(m,a[i]),i);
		dfs(dep+1,s,m,i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum+=a[i];
		MAX=max(MAX,a[i]);
	}
	if(n<=20) {
		dfs(1,0,0,0);
		cout<<ans%mod<<endl;
	}
	else {
		int T[5005];
		T[0]=1;
		for(int i=1;i<=n;i++) {
			for(int j=n;j>=1;j--) {
				T[j]+=T[j-1];
				T[j]%=mod;
			}
		}
		for(int i=3;i<=n;i++) ans+=T[i];
		cout<<ans%mod<<endl;
	}
	return 0;
}
