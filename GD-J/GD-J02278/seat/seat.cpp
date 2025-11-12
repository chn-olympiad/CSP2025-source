#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int N=110;
int n,m;
int ar[N];
int x,lie,hang;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	f(i,1,n*m)
	{
		cin>>ar[i];
	}
	int s=ar[1];
	sort(ar+1,ar+1+n*m);
	int j=1;
	for(int i=n*m;i>=1;i--)
	{
		if(ar[i]==s)
		{
			x=j;
		}
		j++;
	}
	if(x%n==0)
	{
		lie=x/n;
	}
	else
	{
		lie=x/n+1;
	}
	if(lie%2==1)
	{
		if(x%n==0)
		{
			hang=n;
		}
		else
		{
			hang=x%n;
		}
	}
	else
	{
		if(x%n==0)
		{
			hang=1;
		}
		else
		{
			hang=n+1-x%n;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}

