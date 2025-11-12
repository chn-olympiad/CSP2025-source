#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n,a[N],b[N<<1],x,ans;
int main(){
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n),b[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=10001;j++)ans=(ans+b[j])%mod;
		for(int j=10001;j>=0;j--)b[min(10001,j+a[i])]=(b[min(10001,j+a[i])]+b[j])%mod;
	}
	cout<<ans;
	return 0;
}
