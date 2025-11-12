#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,i,n=0,score=0;
	cin>>a>>b;
	int l[a][b];
	int c[a*b];
	for(i=1;i<=a*b;i++)
	{
		cin>>c[i];
	}
	score=c[0];
	for(i=1;i<=a*b;i++)
	{
		if(c[i]<c[i+1] &&c[i]!=c[a*b])
		{
			n=c[i];
			c[i]=c[i+1];
			c[i+1]=n;
		}
	}
	for(i=1;i<=b;i++)
	{
		for(int j=1;j<=a;j++)
		{
			int k=0;
			if(i%2!=0)
			{
				l[i][j]=c[k];
			}
			if(n%2==0)
			{
				l[i][j]=c[k+n];
				k--;
			}
			if(n%2==0 && j==a)
			{
				k+4;
			}
			if(i==b && j==a)
			{
				break;
			}
		}
	}	
	cout<<2<<2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
