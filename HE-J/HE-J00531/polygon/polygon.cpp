#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int a[1000001],arr[1000001];
int main(){
freopen("polygon.in","r","std");
freopen("polygon.out","w","std");
int n,ans=0;
cin>>n;
for (long long i=0;i<n;i++){
	long long x;
	cin>>x;
	a[i]=x;
}
for (long long j=0;j<n;j++){
	for (long long i=0;i<n;i++){
		if (a[i]>a[i+1]){
			int a1,b,c;
			a1=a[i];
			b=a[i+1];
			c=a1;
			a1=b;
			b=c;
			a[i]=a1;
			a[i+1]=b;
		}
	}
}
for (long long x=2;x<=n;x++){
	for (long long i=0;i<=x;i++){
		arr[i]=0;
	}
	for (long long i=0;i<=x;i++){
		long long y=a[i];
		arr[i]=y;
	for (long long j=i+1;j<=x;j++){
		y+=a[j];
		arr[j]=a[j];
	}
for (long long j=0;j<=x;j++){
	for (long long i=0;i<=x;i++){
		if (arr[i]>arr[i+1]){
			int a,b,c;
			a=arr[i];
			b=arr[i+1];
			c=a;
			a=b;
			b=c;
			arr[i]=a;
			arr[i+1]=b;
		}
	}
}
	if ((arr[x]*2)<y) ans++;
}
}
cout<<ans%998 || ans%353 || ans%244;
return 0;
}
