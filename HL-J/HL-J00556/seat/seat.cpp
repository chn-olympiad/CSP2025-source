#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
    int r;
    cin>>r;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
	{
		if(a[i]<=r)
		{
			r=i;
			break;
		}
   }
   int l=1,d=1;	
   if(r/n%2==1)
   {
   	 l=(r+n-1)/n;
   	 d=r-((l-1)*n);
   }
   else if(r/n%2==0)
   {
   	l=(r+n-1)/n;  
    d=r-((l-1)*n)-n+1;
   }cout<<l<<" "<<d;
	return 0;
}
