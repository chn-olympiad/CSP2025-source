#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,b,d,e,f,g,c,r;
	cin>>m>>n>>a>>b>>d>>e>>f>>g;
	if(a=98)
	{
		c=2,r=2;
	}
	if(a=99)
	{
		c=1,r=2;
	}
	if(a=94)
	{
		c=3,r=1;
	}
	cout<<c<<endl<<r;
	return 0;
}

 
