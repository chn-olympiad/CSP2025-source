#include<bits/stdc++.h>
using namespace std;
int n,m,a[111];
int main()
{
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==i)
		{
			
		}
	}
	
	return 0;
}
