#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],x,s=0;
map<long long,long long>p;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	x=a[1];
	for(int i=1; i<n; i++) {
		if(x!=k) x^=a[i+1];
		else {
			x=a[i+1];
			s++;
		}
	}
	if(x==k) s++;
	cout<<s;
	return 0;
}
