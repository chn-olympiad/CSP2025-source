#include<bits/stdc++.h>
#include<iostream>
using  namespace std;
long long n,s,x[500000],a[500001],b[500001],k;
int dd(m,t){
	long long ax=-1,q=1;
	for(int i=m;i>=0;i--){
		if(b[i]==k)ax=max(ax,dd(x[i]-1,t++),q=0;
	}
	if(q==1)return t;
	return ax;
}
int main{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		x[i]=i,b[i]=a[i]
		for(int j=i-1;j>=0;j--){
			if(b[i]==k)break;
			b[i]=b[i]^a[j];
			x[i]=j;
		}
	}
	cout<<dd(n-1,0);
	return 0;
}
