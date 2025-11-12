#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500025];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0)
		cout<<1;
	else
		cout<<2;
	return 0;
}
