#include<bits/stdc++.h>
using namespace std;
int a[101],m,n,s,t,x=0,y=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m*n;i++)
		cin>>a[i];
	s=a[0];
	for(int i=0;i<m*n;i++)
		for(int j=0;j<m*n-i;j++)
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);
	for(int i=0;i<m*n;i++) if(a[i]==s) t=i+1;
	x=t/n;
	if(t%n!=0) x++;
	if(x%2==0)
	{
		y=n-t%n;
		if(t%n!=0) y++;
		if(t%n==0) y=1;
	}
	else
	{
		y=t%n;
		if(t%n==0) y=n;
	}
	cout<<x<<" "<<y;
	return 0;
}
