#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=0,l=0,r=0;
	cin>>n>>m;
	for(int i=0; i<n*m; i++)
	{
		cin>>a[i];
		if(a[0]<a[i])
		{
			k++;
		}
	}
	if(n==1)
	{
		cout<<n<<" "<<k;
	}
	if(m==1||n!=1)
	{
		cout<<k<<" "<<m;
	}
	return 0;
}
