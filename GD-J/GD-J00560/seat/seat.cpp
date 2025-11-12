#include<bits/stdc++.h>
using namespace std;
int a[105]={},n,m,x;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	x=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==x)
		{
			x=i;
			break;
		}
	}	
	cout<<x/n+1<<" ";
	if((x/n+1)%2==0)
	{
		cout<<n-x%n;
	}
	else
	{
		cout<<x%n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
