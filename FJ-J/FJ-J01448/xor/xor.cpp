#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	if(n<=2){
		cout<<1<<'\n';
		return 0;
	}
	cout<<n/2<<'\n';
	return 0;
}
