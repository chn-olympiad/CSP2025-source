#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5005,mod=998244353;
int n,a[N],f[N+114],ans;
int add(int x){
	if(x<0)x+=mod;
	if(x>=mod)x-=mod;
	return x;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=N;j++)ans=add(ans+f[j]);
		for(int j=N;j>=0;j--)f[min(j+a[i],N)]=add(f[min(j+a[i],N)]+f[j]);
	}
	cout<<ans;
	return 0;
}
