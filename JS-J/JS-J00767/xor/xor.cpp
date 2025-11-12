#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) a[i+1]^=a[i];
	if(a[n]==k) cout<<1;
	else cout<<2;
	return 0;
}
//int a,b;
//cin>>a>>b;
//int tmp=(a^b);
//cout<<tmp<<endl;
//ac=tmp^b;
//cout<<ac;!ac=a!
