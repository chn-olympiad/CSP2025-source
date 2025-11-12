#include<bits/stdc++.h>
using namespace std;
int a[10001],n,m,x,y,z,h,b;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	m=1;
	n=1;
	cin>>x>>y;
	z=x*y;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	h=a[1];
	for(int i=1;i<=z;i++){
		if(h<a[i]){
			n=n+1;
		}
	}
	for(int j=1;j<=1;j++){
	if(n<=x){
		break;
	}
	for(int i=1;i<=z;i++){
		if(n>x){
			m=m+1;
			n=n-x;
			if(m%2==0&&n<=x){
				n=x-n;
				n=n+1;
			}
		}
	}
	}
	cout<<m<<" "<<n;
	return 0;
}
