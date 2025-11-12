#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=998244353;
int n,a[N],h[N*N],s[N],f[N],d[N*N],cnt;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
	sort(a+1,a+1+n);
	h[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=s[i];j>=a[i];j--)h[j]=(h[j]+h[j-a[i]])%M;
		for(int j=s[i];j>=1;j--)d[j]=(d[j+1]+h[j+1])%M;
		cnt=(cnt+d[a[i+1]])%M;
	}
	cout<<cnt;
}