#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a1;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if (i==1) a1=a[i];
	}
	int ii;
	sort(a+1,a+(n*m)+1);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==a1) 
		{
			ii=i;
			break;
		}
	}
	ii=(n*m-ii+1);
	int lie=ii/n,hang;
	if (lie*n<ii) 
	{
		hang=ii-(lie*n);
		lie=lie+1;
		cout<<lie<<" ";
	}
	else
	{
		hang=ii-((lie-1)*n);
		cout<<lie<<" ";
	}
	if (lie%2==0) 
	{
		cout<<n-hang+1;
	}
	else cout<<hang;
	return 0;
}