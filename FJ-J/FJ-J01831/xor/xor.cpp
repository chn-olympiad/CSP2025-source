#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k;
int a[N],ans[N],crt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0) cout<<n/2;
	return 0;
}
