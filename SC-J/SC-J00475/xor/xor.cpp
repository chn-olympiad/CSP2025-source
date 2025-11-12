#include<bits/stdc++.h>
using namespace std;
long long n;
const int N=1e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n/2;
	return 0;
}