#include<bits/stdc++.h>
using namespace std;
long long n,a[10000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n+n-1;
	return 0;
}
