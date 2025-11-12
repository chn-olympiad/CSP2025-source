#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[999];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2)cout<<n;
	else	cout<<n/2;
	return 0;
}
