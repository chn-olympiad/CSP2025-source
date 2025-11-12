#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],k=1,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])k++;
	}
	x=(k-1)/n+1;
	y=k-n*x+n;
	if(x%2==0)cout<<x<<" "<<n+1-y;
	else cout<<x<<" "<<y;
	return 0;	
} 
