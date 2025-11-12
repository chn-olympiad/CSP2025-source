#include<bits/stdc++.h>
using namespace std;
long long n,a[50500],k,b[50500],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1]>>ans;
	if((a[1]^ans)==k){
		cout<<2;
		return 0;
	}
	cout<<1;
	return 0;
}