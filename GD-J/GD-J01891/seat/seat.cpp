#include<bits/stdc++.h>
using namespace std;
int a[120],n,m,t,b,lie;
string s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==t)
		{
			b=i;
			break;
		}
	}
	if (b%n!=0)
	{
		lie=m+1-1-b/n;
		cout<<m+1-1-b/n<<" ";
	}
	else {
		lie=m+1-b/n;
		cout<<m+1-b/n<<" ";
	}
	if (b%n==0)
	{
		if (lie%2!=0)
		cout<<"1";
		else cout<<n;
	}
	else if (lie%2!=0)
	{
		cout<<n+1-(b%n);
	}
	else cout<<b%n;
	return 0;
 } 
