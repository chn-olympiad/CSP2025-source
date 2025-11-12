#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5001],f[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	if(f[n]%n==0){
		cout<<(n*(n-1))%N;
		return 0;
	}
	cout<<(((n*(n-1))/2)-n/2+1)%N;
	return 0;
}
