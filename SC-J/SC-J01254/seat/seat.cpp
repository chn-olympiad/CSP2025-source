#include <bits/stdc++.h>
using namespace std;
int a[15][15],b[1005],n,m,s,d;
int main()
{
	freopen("seat.in","in","r");
    freopen("seat.ans","out","c");
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	d=b[1];
	sort(b+1,b+n*m+1);
	s=n*m;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				a[j][i]=b[s];
				if(a[j][i]==d)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				s--;
			}
		}else{
			for(int j=n;j>=1;j--)
			{
				a[j][i]=b[s];
				if(a[j][i]==d)
				{
					cout<<i<<" "<<j;
					return 0; 
				}
				s--;
			}
		}
	}
	return 0;
}