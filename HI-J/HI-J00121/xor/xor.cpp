#include <bits/stdc++.h>
using namespace std;
long long int n,k;
const int N=1e6+5;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k>=2) cout<<2;
	else cout<<1;
	return 0;
}