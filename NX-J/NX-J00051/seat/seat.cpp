#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c[1000000];
	int a,b,oi,n=0,j=1;
	cin>>a>>b;
	for(int i=1;i<=(a*b);i++){
		cin>>c[i];
		}
	int x=a*b;
	oi=c[1];
	sort(c,c+x);
	int m=1;
	for(int m=1;m<=a*b;m++){
		if(c[m]==oi){
			oi=m;
			break;}
		}
	for(int t=1;;t++){
		if(b<t)
		{
			j++;
			}
		if(m==n){
			cout<<j<<" "<<t;
			return 0;}
		n++;}
	return 0;
}
