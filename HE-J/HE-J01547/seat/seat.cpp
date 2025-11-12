#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	
	int n,m,o,z1,z2;
	//cin>>n>>m;
	scanf("%d",&n);
	scanf("%d",&m);
	int a[n*m];
	int x=n,y=m;
	for(int i=0;i<n*m;i++)
	{
		//cin>>a[i];
		scanf("%d",&a[i]);
	}
	o=a[0];
	sort(a,a+n*m);
	
	for(int j=0;j<n*m;j++)
	{
		if(a[j]==o)
		{
			o=j+1;
			
		}
		
	}
//	cout<<o;

	if(o%n==0)
	{
		z1=o/n;
	}
	else
	{
		z1=o/x+1;
	}
	for(;z1>0;z1--)
	{
		m--;
	}
//	//ап 
	if((m+1)%2==0)
	{
		z2=m-o%x;
	}
	else
	{
		z2=o%x;
	}
	//cout<<m+1<<" "<<z2+1;
	printf("%d",m+1);
	cout<<" ";
	printf("%d",z2+1);
	return 0;
} 
