#include<bits/stdc++.h>
using namespace std;
int a[100],b[100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n*m;i++)
	{
			if(b[1]==a[i])
			{
				break;
			}
	}
	cout<<i;
	return 0;
}
