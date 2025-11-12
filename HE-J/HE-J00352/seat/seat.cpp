#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],c[15][15],q=1;
bool fl=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin >> n >>m;
    for (int i=1;i<=n*m;i++)
    {
    	cin >> a[i];
	}
	b[a[1]]=1;
	sort (a+1,a+n*m+1,greater<int>());
	for (int i=1;i<=m;i++)
	{
		if (i%2==0)
		{
			for (int j=n;j>=1;j--)
		    {
			    c[i][j]=a[q];
			    q++;
			    if (b[c[i][j]]==1)
			    {
			    	cout << i << " "<< j;
					fl=1; 
				}
		    } 
		}
		else
		{
			for (int j=1;j<=n;j++)
		    {
			    c[i][j]=a[q];
			    q++;
			    if (b[c[i][j]]==1)
			    {
			    	cout << i << " "<< j;
					fl=1; 
				}
		    } 
		}
		if (fl) break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

