#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s=1,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			s++;
		}
	}
	c=s/n;
	r=s%n;
	if(r==0){
		r=n;
	}
	else{
		c++;
	}
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
