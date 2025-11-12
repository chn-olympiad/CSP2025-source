#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],tmp=0;
int ans=0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]=a[i-1] xor a[i];
		int need=a[i] xor k;
		int lct=find(a+tmp,a+i+1,need)-a;
		if(lct<i)ans++,tmp=i;
	}
	cout<<ans;
	return 0;
}
