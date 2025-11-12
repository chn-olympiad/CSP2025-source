#include<bits/stdc++.h>
using namespace std;
int main()
{   freopen("r","seat.in",stdin);
    freopen("w","seat.out",stdout);
    int n,m;
    cin>>n>>m;
    int s[n*m+6],g;
    for(int i=1;i<=n*m;i++)
    {
		 cin>>s[i];
	}
    g=s[1];
    sort(s+1,s+1+n*m);
    int k=0;
    for(int i=1;i<=n*m;i++)
    {
		if(s[i]==g)
		{
			k=n*m-i+1;
			break;
		}
	}
	int sum=1;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(sum==k)
			{
				cout<<j<<" "<<i;
				return 0;
			}
			else sum++;
		}
		j++;
		for(int i=n;i>=1;i--)
		{
			if(sum==k)
			{
				cout<<j<<" "<<i;
				return 0;
			}
			else sum++;
		}
	}
	
    return 0;
}
