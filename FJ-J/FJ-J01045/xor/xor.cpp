#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in ","r",stdin);
	freopen("xor.out ","w",stdout);
	int a[5100],b,c[10000],d,o=0;
	cin>>b>>d;
	for(int i=1;i<=b;i++){
		cin>>a[i];
		o+=a[i];
	}
	cout<<o;
	return 0;
}
