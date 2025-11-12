#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long i,j,n,sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long ans=0,a[n];
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=n-i;j++){
		ans++;
	}
	cout<<ans;
	return 0;
}
