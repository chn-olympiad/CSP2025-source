#include<bits/stdc++.h>
using namespace std;
int s[20][20];
int a[10000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int y=a[1];
	sort(a+1,a+n*m+1);
	int flag=1;
	for(int i=m;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			if(i%2==0)
			{
				s[m-j+1][i]=a[flag];
				if(a[flag]==y)
				{
					cout<<i<<" "<<m-j+i<<"\n";
					return 0;
				}
			}
			else
			{
				s[j][i]=a[flag];
				if(a[flag]==y)
				{
					cout<<i<<" "<<j<<"\n";
		  			return 0;
				}
			}
			flag+=1;
		}
	}

}
 