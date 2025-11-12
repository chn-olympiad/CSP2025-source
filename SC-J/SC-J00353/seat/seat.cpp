#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r,a[105],b[15][15],x;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int i=1;
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(c=1;c<=m;c++)
	{
		if(c%2==1)
		{
			for(r=1;r<=n;r++)
			{
				b[c][r]=a[i];
				if(a[i]==x)
				{
					cout<<c<<' '<<r<<endl;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				i++;
			}			
		}
		else 
		{
			for(r=n;r>=1;r--)
			{
				b[c][r]=a[i];
				if(a[i]==x)
				{
					cout<<c<<' '<<r<<endl;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				i++;
			}					
		}
	}
	return 0;
}