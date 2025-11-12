#include<bits/stdc++.h>
using namespace std;
int a[21][21];
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
   int k=a[1];
   sort(a+1,a+1+n);
   int n;
   for(int i=1;i<=n;i++)
   {
   	if(a[i]==k)
   	{
   	  
	}
   }
}
