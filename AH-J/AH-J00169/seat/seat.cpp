#include<bits/stdc++.h>
using namespace std;
int a[101],b[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	cin>>a[1];
	s=a[1];#include<bits/stdc++.h>
using namespace std;
int a[101],b[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	cin>>a[1]
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+1+n*m);
	int w=n*m;
	for(int i=1;i<=n*m;i++)
	{
		b[w]=a[i];
		w--;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[(i-1)*n+j]==s)
			{
				if(i%2==0) j=n-j+1;
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
