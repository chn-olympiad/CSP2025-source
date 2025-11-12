#include<bits/stdc++.h>
using namespace std;
long long i,j,n,a[5];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+n+4);
	if(a[1]+a[2]>a[3])cout<<1;
	return 0;
} 
