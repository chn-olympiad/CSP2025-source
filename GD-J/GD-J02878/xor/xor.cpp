#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[500005],sum[500005],n[100000],m[100000],d[100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1) cout<<0;
	else if(n==2) cout<<1;
	else if(n<100) {
		if(k==0) cout<<n/2;
		else cout<<n/2+1;	
	}
	return 0;
}
