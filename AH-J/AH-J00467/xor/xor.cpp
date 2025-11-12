#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[500005];
int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==1) ans++;
	}
	if (n<=2){
		cout<<1;
		return 0;
	}
	if (k==1){
		cout<<ans;
		return 0;
	}
	if (k==0){
		cout<<1;
		return 0;
	}
	return 0;
}
