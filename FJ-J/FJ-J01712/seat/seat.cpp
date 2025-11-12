#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],s[12][12];
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		cin>>a[i];
	int q=a[1];
	sort(a+1,a+m*n+1,cmp);
	int o=1;
	for (int i=1;i<=m;i++)
	{
		if (i%2==1){
		    for (int j=1;j<=n;j++)
			{
				s[i][j]=a[o];
				o++;
			}
		}
		else
		{
			for (int j=n;j>=1;j--)
			{
				s[i][j]=a[o];	
				o++;
			}
		}
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if (s[i][j]==q)
				cout<<i<<" "<<j;
	return 0;
 } 
