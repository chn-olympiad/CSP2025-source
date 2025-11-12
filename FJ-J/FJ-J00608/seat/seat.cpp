#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],s[10][10],r,aj=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	r=a[0];
	for(int i=0;i<n*m;i++)
		for(int j=0;j<n*m-1-i;j++)
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
	for(int i=0;i<m;i++)
	{
		if((i+1)%2==0)
		{
			for(int j=n-1;j>=0;j--)
			{
				s[i][j]=a[aj];
				aj++;
				if(s[i][j]==r)
				{
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
		else
		{
			for(int j=0;j<n;j++)
			{
				s[i][j]=a[aj];
				aj++;
				if(s[i][j]==r)
				{
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
