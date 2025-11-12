#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	int me=a[0];
	for(int i=0;i<n*m;i++)
	{
		for(int j=i+1;j<n*m;j++)
		{
			if(a[i]<a[j])
			{
				int p=a[i];
				a[i]=a[j];
				a[j]=p;
			}
		}
	}
	int sum[n][m],me_i;
	for(int i=0;i<m*n;i++)if(a[i]==me)me_i=i;
	int i=me_i%n,j=me_i/n+1;
	if(j%2==1)i=i+1;
	else i=n-i;
	cout<<j<<" "<<i;
	return 0;
}