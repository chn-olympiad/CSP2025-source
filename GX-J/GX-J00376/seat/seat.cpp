#include <bits/stdc++.h>
using namespace std;
int n,m,c,e,f,g,h,j;
int a[110],b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
cin>>n>>m;
	c=n*m;
for (int i = 0; i < c; i++){
	cin>>a[i];
}
j=a[0];
sort(a,a+c);
for (int i = c-1; i >= 0; i--){
	b[e]=a[i];
	e++;
}
for (int i = 0; i < c; i++){

	if(b[i]==j) {
		f=i+1;
		}
}
if(f%m==0){
	g=1;
	h=m;
	}
	else{
		g=f/m+1;
		h=f%m;
		}
cout<<g<<" ";
if(g==1||m%2!=0) {
	cout<<h;
	}
else {
	cout<<n-h+1;
	}
return 0;
}

