#include<iostream>
#include<cstdio>
using namespace std;
int n,m,z,w=1,x,y;
int c[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>c[i];
	z=c[1];
	for(int i=2;i<=n*m;i++)
		if(z<c[i]) w++;
	x=w/m;
	if(w>m)
		x=x+1;
	y=w-(x-1)*n;
	if(x%2==0){
		y=n-y+1;
	}	
	if(m==1)
		x=n;
		y=m;
	cout<<x<<" "<<y;
	return 0;
} 
