#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,a[117],v,x;
	cin>>n>>m;
	x=n*m;
	for(int i=0;i<=x;i++){
		cin>>a[i];
	}
	v=a[1];
	sort(a+1,a+1+x);
	for(int i=0;i<=x;i++){
		if(v==a[i]){
			c=i/n;
			r=i%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
