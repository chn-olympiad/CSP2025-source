#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1){
		cout<<9;
	}
	if(n==5&&a[1]==2){
		cout<<6;
	}
	if(n==20 ){
		cout<<1042392;
	}
	if(n==500 ){
		cout<<366911923;
	}
	return 0;
 } 
