#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,a[100];
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	a1=a[1];
	for(int i=0;i<n*m;i++)
	{
		for(int j=n*m;j>i;j--)
			if(a[j]>a[j-1])
			{
				int w=a[j];
				a[j]=a[j-1];
				a[j-1]=w;
			}
		if(a1==a[i])
		{
			cout<<(i+1)/n+1<<' ';
			i/n%2==1?cout<<n-i%n<<endl:cout<<i%n+1<<endl;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
