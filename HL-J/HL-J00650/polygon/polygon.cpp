#include <bits/stdc++.h>
using namespace std;
int n,a[1000000],m,cnt,h;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n-3;i++){
		m=a[i+2];
		if(a[i+1]+a[i]+a[i+2]>m*2)
		h++;
	}
		for(int i=1;i<=n-4;i++){
		m=a[i+3];
		if(a[i+1]+a[i]+a[i+2]+a[i+3]>m*2)
		h++;
	}
		for(int i=1;i<=n-5;i++){
		m=a[i+4];
		if(a[i+1]+a[i]+a[i+2]+a[i+3]+m>m*2)
		h++;
	}
	cout<<h;
	return 0;
}
