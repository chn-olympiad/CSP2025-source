#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a,x,j=1;
	cin>>m>>n;
	cin>>a;
	for(int i=2;i<=m*n;i++)
	{
		cin>>x;
		if(x>a)
			j++;
	}
	if(j%n==0)
	{
		
		if(j/n%2==0)
			cout<<1;
		else
			cout<<n;
		cout<<' '<<j/n;
	}
	else
	{
		cout<<j/n+1<<" ";
		if(j/n%2==0)
		{
			cout<<j%n;
		}
		else{
			cout<<n-j%n+1;
		}
	}
	return 0;
}