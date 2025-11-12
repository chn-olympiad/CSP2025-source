#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5000005],ans=3,f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(!f) ans=2;
	cout<<ans;
	return 0;
}
