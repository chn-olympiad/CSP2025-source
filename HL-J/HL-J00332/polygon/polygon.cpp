#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long h,c,s,g=0;
	cin>>h;
	int a[h];
	for(int i=0;i<h;i++){
		cin>>a[i];
	}
	for(int i=0;i<h;i++){
		if(a[i]<a[i+1]){
			c=a[i];
			a[i]=a[i+1];
			a[i+1]=c;
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<h;j++){
			for(int h=i;h<=j;h++){
				g=g+a[i];
			}
			if(a[i]>g){
				s++;
			}
		}
	}
	cout<<s%998244353;
	return 0;
}
