#include<bits/stdc++.h>
using namespace std;
long long k,n,m,a[666666],b[666][666],l=1,o1,o2,p=1,q;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				b[i][j]=a[p];
				if(b[i][j]==k) cout<<i<<' '<<j;
				p++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				b[i][j]=a[p];
				if(b[i][j]==k) cout<<i<<' '<<j;
				p++;
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
