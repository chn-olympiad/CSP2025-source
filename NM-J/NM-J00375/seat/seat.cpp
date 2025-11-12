#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int seat,pos;
int a[105];
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
   cin>>n>>m;
   int cap=n*m;
   for(int i=1;i<=n;i++)
   {
   	cin>>a[i];
   	x=a[i];
   	soft(a+1,a+cap+1);
   	for(int i=cap;i>=1;i--)
   	seat++;
   	  if(a[i]==x)
   	    {
   	    	pos=seat;
		   }
   }
   int x=pos/n;
   if(x==0)
   	x=1;
   x++;
   int y;
   if(x%2==1)
   	y=pos%n;
   	else y=n-pos%n+1;
   cout<<x<<" "<<y;
fclose(stdin);
fclose(stdout);
return 0;
}
