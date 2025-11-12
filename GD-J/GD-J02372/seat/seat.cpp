#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,m,a[200],t=0,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) t++;
	}
	c=t/n+1;
	if(c%2==1){
		r=t%n+1;
	}
	else{
		r=n-t%n;
	}
	cout<<c<<" "<<r;
	return 0;
 } 
 /*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/
