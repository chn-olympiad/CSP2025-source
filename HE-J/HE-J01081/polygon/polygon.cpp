#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],s=0;
int main( ){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=1;i<=n-2;i++){
		if(a[i]+a[i+1]+a[i+2]>a[i+2]*2)s+=1;
	}
	for(int i=1;i<=n-3;i++){
		if(a[i]+a[i+1]+a[i+2]+a[i+2]>a[i+3]*2)s+=1;
	}
	for(int i=1;i<=n-4;i++){
		if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>a[i+4]*2)s+=1;
	}
	cout<<s;
	return 0;
}
