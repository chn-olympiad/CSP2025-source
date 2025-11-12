#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b,c,d,e=0;
int main()
{
	fropen("seat.in","r",stdin);
	fropen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	b=a[1];
	sort(a+1,a+n*m+1);
	if(a[n*m]==b)
	{
		cout<<"1"<<" "<<"1";
		return 0;
	}
	d=m;
	if(d%2==0)
	{
		c=1;
		e=1;
	}
	if(d%2!=0)
	  c=n;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			printf("%d %d",d,c);
			return 0;
		}
		    if(c==n&&d%2==0)
		    {
			    c=n;
			    d--;
			    continue;
		    }
			if(c==1&&d%2!=0)
		    {
			    c=1;
			    d--;
			    continue;
		    }
		    if(d%2!=0)
		    {
			    c--;
			    continue;
		    }
		    if(d%2==0)
		    {
			    c++;
			    continue;
		    }
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
