#include<bits/stdc++.h>
using namespace std;
int n;
int big(int a,int b,int c){
	int v=0;
	if (a>=b&&a>=c)v=a;
	if (b>=a&&b>=c)v=b;
	if (c>=a&&c>=b)v=c;
	return v;
}
int g=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int m[n];
	for (int i=0;i<n;i++){
		cin>>m[i];
	}
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			for (int z=j+1;z<n;z++){
				if (big(m[i],m[j],m[z])*2<m[i]+m[j]+m[z])g++;
			}
		}
	}
	cout<<g;
	return 0;
}
