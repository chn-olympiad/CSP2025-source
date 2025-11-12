#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[10001];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	cout<<a[0] xor a[1];
	return 0;
}
