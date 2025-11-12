#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
int a[500005];
ll ans,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
		if(a[i]==k)
			ans++;
	for(int i=1;i<=n;++i)
		if(a[i]==a[i+1] && a[i]==1)
			sum++,i++;
	if(k==0) cout<<ans+sum;
	else if(k==1) cout<<ans;
	
	return 0;
}
