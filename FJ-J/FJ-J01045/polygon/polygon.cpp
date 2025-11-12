#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[5100],b,c[10000],d,o=0;
	cin>>b;
	for(int i=1;i<=b;i++){
		cin>>a[i];
		o+=a[i];
	}
	cout<<o;
	
	
	return 0;
}
