#include<bits/stdc++.h>
#include<iostream>
using  namespace std;
long long n,a[5000],m;
int qq(c,t){
	long long f=0,r[5001];
	r[0]=0;
	for(int i=1;i<=c;i++){
		r[i]=a[i-1]+r[i-1];
		for(int j=i-1;j>=0;j--){
			if(r[i]-r[j]>t)f=(f+1)%998244353;
		}
	}
	return f;
}
int main{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++{
		cin>>a[i];
		for(int j=i-1;j>0;j--){
			m=(m+qq(j-1,a[i]-a[j]))%998244353;
		}
	}
	cout<<m;
	return 0;
}
