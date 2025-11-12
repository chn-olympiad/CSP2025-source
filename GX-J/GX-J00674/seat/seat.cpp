#include <iostream>
using namespace std;
int n,m,a1,a[105],n1,m1,ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	a1=a[1];
	for(int i=1;i<=n*m;i++)
	{
		if(a1<a[i])
		{
			ans+=1;
		}
	}
	m1=1;
	n1=1;
	for(int i=ans;i>0;i--)
	{
		if(n1%2==0)
		{
			if(m1>1)
			{
				m1--;
				ans--;
			}
			else
			{
				n1++;
				m1=1;
				ans--;
			}
			continue;
		}
		if(n1%2==1)
		{
			if(m1<m)
			{
				m1++;
				ans--;
			}
			else
			{
				n1++;
				m1=m;
				ans--;
			}
			continue;
		}
		
	}
	cout<<n1<<" "<<m1;
	return 0;
}

