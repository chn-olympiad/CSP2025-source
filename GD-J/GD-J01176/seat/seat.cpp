#include <iostream>
using namespace std;
int a[100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,study;
	int cnt,o;
	cin>>n>>m;
	cin>>study;
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=n*m;i++)
	{
		if(study>a[i])
		{
			cnt=i;
			o = i;
			break;
		}

	}
	for(int i=o;i<=n*m;i++)
	{
		if(a[i]>study)
		{
			cnt++;
		}
	}
	int nt = 2*n;
	if(cnt%nt > n)
	{
		cout<<cnt/n+1<<" "<<n-cnt%n+1;
	}
	if(cnt%nt < n&& cnt%nt!=0)
	{
		cout<<cnt/n+1<<" "<<cnt%n;
	}
	if(cnt%nt==0)
	{
		cout<<cnt/n<<" "<<"1";
	}
	if(cnt%nt==n)
	{
		cout<<cnt/n<<" "<<n;
	}
	
	
	
	
	
	return 0;
}

