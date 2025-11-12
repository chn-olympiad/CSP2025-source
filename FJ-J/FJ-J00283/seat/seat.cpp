#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,x,t=1,c,r,a[100];
	cin>>n>>m;
	int y=n*m;
//	cout<<y<<endl;
	for(i=0;i<y;i++)
		cin>>a[i];
	x=a[0];
	for(i=1;i<y;i++)
		if(a[i]>x)
			t++;
//	cout<<t<<endl;
	c=(t-1)/n+1;
	if(c%2==0)
		r=n-t%n+1;
	else
		r=(t-1)%n+1;
	cout<<c<<" "<<r<<endl;
	return 0;
}
