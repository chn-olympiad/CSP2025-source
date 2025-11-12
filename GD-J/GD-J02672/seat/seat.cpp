#include <bits/stdc++.h> 
using namespace std;
const int MAX=105;
int n,m,score,wz;
int t;
int a[MAX];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	score=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m/2;i++)
	{
		t=a[i];
		a[i]=a[n*m-i+1];
		a[n*m-i+1]=t;
	}
	for(int i=1;i<=n*m;i++)
	{
		if (a[i]==score)
		{
			wz=i;
		}
	}
	if (wz%n==0)
	{
		cout<<wz/n<<' ';
	}
	else
	{
		cout<<wz/n+1<<' ';
	}
	if (wz/n%2==0)
	{
		if (wz%n!=0)
		{
			cout<<wz%n<<endl;
		}
		else
		{
			cout<<n<<endl;
		}
	}
	else
	{
		if(n-wz%n!=n)
		{
			cout<<n<<endl;
		}
		else
		{
			cout<<n-wz%n<<endl;
		}
	}
	return 0;
}

