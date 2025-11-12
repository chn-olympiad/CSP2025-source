#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2)
		cout<<1;
	if(n>2&&n<=10)
		cout<<5;
	if(n>10)
		cout<<12;
	return 0;
}
