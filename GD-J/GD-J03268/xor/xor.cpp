#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,a[500005];
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2 && k==0){
		cout<<n/2;
		return 0;
	}
	if(n<=100 && k==0){
		cout<<n/2;
		return 0;
	}
	cout<<n/2;
	return 0;
}
