#include<iostream>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n],i,j,l,t,b=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;)
	{
		for(j=0;j<n;j++)
		{
			t=a[i];
			for(l=0;l<=j;l++)
			{
				t=t^a[l];
			}
			if(t==k)
			{
				b++;	
			}
		}
		n--;
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
