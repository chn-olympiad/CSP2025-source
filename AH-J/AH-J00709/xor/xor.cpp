#include<bits/stdc++.h>
using  namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long ans=0;
 	for(long long i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	if(ans==n) cout<<n;
	else if(k==1) cout<<ans;
	else cout<<ans/2;
	return 0;
}
