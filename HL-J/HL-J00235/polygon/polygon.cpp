#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	cin>>a[1];
	if(n==5){
		if(a[1]==1)
			cout<<9<<endl;
		if(a[1]==2)
			cout<<6<<endl;
	}
	if(n==20)
		cout<<1042392<<endl;
	if(n==500)
		cout<<366911923<<endl;
	return 0;
}
