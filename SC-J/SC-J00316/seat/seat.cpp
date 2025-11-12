#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int sc1[105],sc[105],asdf=0,pos;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
	    cin>>sc1[i];
	int tldhz=sc1[1];
	sort(sc1+1,sc1+n*m+1);
	for (int i=1;i<=n*m;i++) sc[i]=sc1[n*m-i+1];
	for (int i=1;i<=n*m;i++)
	    if (sc[i]==tldhz) 
		{
			pos=i;
			break;
		}
	for (int i=1;i<=m;i++)
	{
	    if (i%2==1)
	    {
	    	for (int j=1;j<=n;j++) 
			{
			    asdf++;
				if (asdf==pos)
				{
				    cout<<i<<' '<<j;
				    return 0;
				}	
			} 
		}
		else
	    {
	    	for (int j=n;j>=1;j--) 
			{
			    asdf++;
				if (asdf==pos)
				{
				    cout<<i<<' '<<j;
				    return 0;
				}	
			} 
		}
	}
}