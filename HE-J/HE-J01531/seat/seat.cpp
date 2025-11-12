#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int n,m,b[105],c,q;
int main()
{
	cin >>n >>m;
	for(int i=1;i<=m*n;i++)
	{
		cin >>b[i];
	}
	q=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i]==q && c==0)
			{
				cout <<i <<' ' <<j;
				c++;
			}
		}
	}
	return 0;
}

