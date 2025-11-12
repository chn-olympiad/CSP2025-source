#include<bits/stdc++.h>
using namespace std;
int n,m,R,a[110],nm;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    nm=n*m;
    for (int i=1;i<=nm;i++)
    	cin>>a[i];
    R=a[1];
    sort(a+1,a+nm+1);
    for (int j=1;j<=m;j++)
    {
    	if (j%2==1)
    		for (int i=1;i<=n;i++)
    		{
    			if (a[nm]==R)
    			{
    				cout<<j<<' '<<i;
    				return 0;
				}
				nm--;
			}
		else
			for (int i=n;i>=1;i--)
    		{
    			if (a[nm]==R)
    			{
    				cout<<j<<' '<<i;
    				return 0;
				}
				nm--;
			}
	}
    return 0;
}

