#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,b,c,d,e,f,x[100100],y[100100],z[100100],m[100100],n[100100],q=0,k,l=0,u=1,ma=0,mb=0,mc=0;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b;
		c=b/2;
		for(int j=1;j<=b;j++)
		{
			cin>>x[j]>>y[j]>>z[j];
			l+=y[i]+z[i];
		}
		if(l==0)
		{
		    sort(x+1,x+b+1);
		    for(int k=b;k>c;k--)
		  {
			q+=x[k];
		  }
		  cout<<q;
		  q=0;
		  continue;
		}
	}
	return 0;
 } 
