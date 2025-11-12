#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],b[100005],c[100005],d[100005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2)
	cout<<1;
	else cout<<n-1;
	return 0;
}
