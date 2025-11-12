#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],x,a1,x1,i;

bool h()
{
	
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	
	a1=a[0];
	for(i=0;i<n*m;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				x=a[i];
				a[i]=a[j];
				a[j]=x;
			}
		}
	}
	
	for(i=0;i<n*m;i++)
	{
		if(a[i]==a1)
		{
			x1=i;
		}
		
	}
	x1+=1;
	if(x1%(2*n)>n)
	{
		cout<<(x1-1)/n+1<<" "<<n-(x1%(2*n)-n)+1;
	}
	else
	{
		cout<<(x1-1)/n+1<<" "<<x1%(2*n);	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
