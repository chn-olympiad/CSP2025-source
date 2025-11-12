#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,n1=1,m1=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n*m;j++)
	{
		if(a[1]<a[j]&&m1<=m)
		{
			m1+=1;
		}
		else if(a[1]<a[j]&&n1<=n)
		{
			n1+=1;
		}
	}
	cout<<n1<<" "<<m1;
	return 0;
 } 
