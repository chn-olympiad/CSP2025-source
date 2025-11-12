#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,a[5001];
long long ff;
int mxan;
long long h;
int bijiao(int x,int y,int k){
	if(x>y && x>k) return x;
	else if(y>x && y>k) return y;
	else if(k>y && k>x) return k;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=2;i<n;i++){
		for(int j=1;j<i;j++){
			for(int k=0;k<j;k++){
				mxan=bijiao(a[i],a[j],a[k]);
				h=a[i]+a[j]+a[k];
				if(h>mxan*2) ff++;
			}
		}
	}
	cout<<ff; 
	return 0;
}
