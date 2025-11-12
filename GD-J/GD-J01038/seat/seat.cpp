#include<bits/stdc++.h>
using namespace std;
const int N=1e4+2;
int m,n;
int a,cj,lon=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>cj;
	for(int i=1;i<m*n;i++){
		cin>>a;
		if(a>cj)lon++;
	}
	int c=(lon+n-1)/n,r=lon%n;
	if(r==0)r=n;
	if(c%2==0)r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}
