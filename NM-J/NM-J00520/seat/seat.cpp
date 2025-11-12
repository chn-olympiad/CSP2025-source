#include<bits/stdc++.h>
using namespace std;
int s[102];
bool ttt(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,q,k=0;
	cin>>n>>m;
	cin>>s[0];
	q=s[0];
	for(int i=1;i<n*m;i++)
	{
		cin>>s[i];
	}
	sort(s,s+n*m,ttt);
	for(int i=0;i<m;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<n;j++)
			{
				if(s[k]==q)
				{
					cout<<++i<<' '<<++j;
					return 0;
				}
				k++;
			}
		}
		else
		{
			for(int j=n-1;j>=0;j--)
			{
				if(s[k]==q)
				{
					cout<<++i<<' '<<++j;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
