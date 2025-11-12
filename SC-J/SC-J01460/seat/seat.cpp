#include<bits/stdc++.h>
using namespace std;

int n,m,a,b[15],c[15],d=0,e=0,f=0,g=0; 
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a=n*m;
	for (int i=1;i<=a;i++){
		cin>>b[i];
	}
	for (int i=1;i<=a;i++){
		c[i]=b[i];
	}
	for (int i=2;i<=a;i++){
			if (c[i]>c[i-1])
			swap(c[i],c[i-1]);
	}
	for (int i=1;i<=a;i++){
		if (c[i]==b[1])
		d=i;
	}
	g=d/m;
	if (d%m!=0)
	e=d/m+1;
	else
	e=d/m;
	if (d%n!=0||g%2!=0)
	f=d%n;
	else
	f=n-(d%n||g%2==0);
	cout<<e<<" "<<f;
	return 0;
}