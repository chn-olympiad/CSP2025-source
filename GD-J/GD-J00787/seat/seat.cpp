#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[105],x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>=a[1]) r++; 
	}
	x=(r+n-1)/n;
	r%=(2*n);
	if(r==0) r=2*n;
    if(r>n)  r=n+1-(r-n);
	cout<<x<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
