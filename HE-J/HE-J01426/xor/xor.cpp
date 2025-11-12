#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[225];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if((n+k)%2){
		cout<<1;
	}
	else{
		cout<<2;
	}
	return 0;
}
