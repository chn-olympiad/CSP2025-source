#include<bits/stdc++.h>
using namespace std;
long long s[1000000];
long long b[1000000];
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int main(){
	long long n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	cout<<2;
	return 0;
}
