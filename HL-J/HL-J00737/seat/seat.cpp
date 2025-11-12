#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("problem","r",stdin);
	freopen("problem","w",stdout);
	int n,m,sum=0,b=0;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[i+1])
		{
			a[i]=a[i+1];
			if(a[i]>a[1])
			{
				sum++;
			}
		}
	}
	if(sum%m==0)
	{
		b=sum;
		sum/=m;
		b%=m;
		if(sum%2==0)
		{
			b=(m+1)-b;
		}
		cout<<sum<<" "<<b;	
	}
	else{
		sum/=m;
		b%=m;
		if(sum%2==0)
		{
			b=(m+1)-b;
		}
		cout<<sum+1<<" "<<b;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}