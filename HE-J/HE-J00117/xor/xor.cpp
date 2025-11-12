#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],k,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ks=1;
	for(int j=1;j<=n;j++){
		long long x=a[ks];
		for(int b=ks+1;b<=j;b++){
			x=x^a[b];
		}
		if(x==k){
			s++;
			ks=j+1;
		}
	}
	cout<<s;
	return 0;
}
