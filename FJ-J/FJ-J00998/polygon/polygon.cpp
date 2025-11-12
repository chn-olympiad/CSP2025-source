#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int main() {
	//12·Ö
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,k=0,j=0,x=0;
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		k=max(k,a[i]);
		j+=a[i];
	}
	if(j>2*k) cout<<"1";
	else cout<<"0";
	return 0;
}
