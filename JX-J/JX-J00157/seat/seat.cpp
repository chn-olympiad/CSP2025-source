#include<bits/stdc++.h>
using namespace std;
int a[120];
int main()
{
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   int m,n;
   cin>>n>>m;
   int s=m*n;
   for(int i=1;i<=m*n;i++)
    {
	   cin>>a[i];
	   if(a[i]<a[1])s--;
	}
	int k;
	if(s%m==0)
	{
		k=s/m;
		cout<<k<<" ";
		if(k%2==0)cout<<"1";
		else cout<<n;
	}
	else if(s%m!=0)
	{
		k=s/m+1;
		cout<<k<<" ";
		int p=k-1;
		if(k%2!=0)cout<<s-n*p;
		else cout<<n+1-(s-n*p);
	}
   return 0;
}
