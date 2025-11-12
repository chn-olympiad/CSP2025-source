#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=2;i<=n;i+=2) for(int j=0;j<i;j++) s+=(n-j)/i;
	cout<<s;
	return 0;
}
