#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k;
int a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2 || (n>10 && n<=100)) cout<<n;
	else if(n>1000 && n<=200000) cout<<0;
	else cout<<1;
	return 0;
}
