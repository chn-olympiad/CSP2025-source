#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,x=1,y=1,z;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	cin>>a[1],t=a[1];
	for(int i=2; i<=n*m; i++)
		cin>>a[i];
	sort(a+1,a+n*m+1);
	for(int i=n*m; i>=1; i--)
	{
		if(a[i]==t)cout<<x<<" "<<y;
		if(z==0)
		{
			y++;
			if(y==n+1)y=n,x++,z=1;
		}
		else if(z==1)
		{
			y--;
			if(y==0)y=1,x++,z=0;
		}
	}
	return 0;
} 
