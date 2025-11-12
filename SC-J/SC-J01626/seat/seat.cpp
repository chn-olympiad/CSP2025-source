#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],s,x,y,f;
	cin>>n>>m;
	for (int i=1;i<=m*n;i++)
	  cin>>a[i];
	f=a[1];
	s=n*m;
	for (int j=1;j<=m*n;j++)
	{
		for (int i=1;i<s;i++)
	    {
		if (a[i+1]>a[i])  swap(a[i+1],a[i]);
	    }
	    s=s-1;
	}
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==f)
		{
			x=(i-1)%n+1;
			y=(i-1)/n+1;
		}
	}
	cout<<y<<" "<<x;
	return 0;
} 