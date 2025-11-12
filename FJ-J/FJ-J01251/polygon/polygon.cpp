#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],s[5005];
int cc[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	if(a[n]*2>s[n])cout<<1%mod;
	return 0;
	
}
