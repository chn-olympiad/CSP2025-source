#include<bits/stdc++.h> 
using namespace std;
int main(){
//	freopen("seat1.in","r",stdin);
//	freopen("seat1.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int c=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=m*n;j++)
		{
			if(a[i]<a[j])
			{
				int d=a[i];
				a[i]=a[j];
				a[j]=d;
			}
		}
	}
	int e=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==c)
		{
			e=i;
			break;
		}
	}
	int o=0;
	if(e%n==0)
	{
		o=e/n;
	}
	else
	{
		o=e/n+1;
	}
	if(o%2!=0)
	{
		if(e%n==0)
		{
			cout<<e/n<<" "<<e-(e/n-1)*n;
		}
		else
		{
			cout<<e/n+1<<" "<<e-e/n*n;
		}
	}
	else if(o%2==0)
	{
		if(e%n==0)
		{
			cout<<e/n<<" "<<n+1-e+(e/n-1)*n;
		}
		else
		{
			cout<<e/n+1<<" "<<n+1-e+e/n*n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
