#include<bits/stdc++.h>
using namespace std;
int a[101],sign[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		sign[i]=i;
	}
	for(int i=0;i<n*m;i++)
	{
		for(int j=0;j<n*m-i;j++)
		{
			if(a[j+1]>a[j])
			{
				int c=a[j+1],b=sign[j+1];
				a[j+1]=a[j];
				a[j]=c;
				sign[j+1]=sign[j];
				sign[j]=c;
			}
		}
	}
	int ansn=1,ansm=1;
	for(int i=0;i<n*m;i++)
	{
		if(sign[i]==0)
		{
			cout<<ansn<<" ";
			if(ansn%2==1)
			{
				cout<<ansm;
			}
			else
			{
				cout<<m+1-ansm;
			}
		}
		ansm++;
		if(ansm>m)
	    {
	    	ansn++;
	    	ansm=1;
		}
	}
	return 0;
}