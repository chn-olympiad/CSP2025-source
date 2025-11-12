#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
	int n,m;
	int x,r[199];
	cin>>n>>m;
	int a=n*m;
	for(int i=1;i<=a;i++){
		cin<<a[i];
	}
	for(int i=1;i<=a-1;i++){
		if(a[i]<a[i+1]){
			r[i]=a[i+1];
			a[i+1]=a[i];
			r[i]=a[i];
			x++;
		}
	}
	m=x/m;n=n-m;
	cout<<m<<" "<<n;
	return 0;
 }
