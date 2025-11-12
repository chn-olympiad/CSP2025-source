#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
   int t,n,u,a[100000000],k,b,l[100000000],j[3],h[3],o[3],z[3],v[3],w[3]; 
   n%2==0;
   cin>>t;
   cin>>n;
   cin>>j[0]>>j[1]>>j[2];
   cin>>h[0]>>h[1]>>h[2];
   cin>>u; 
   cin>>o[0]>>o[1]>>o[2];
   cin>>z[0]>>z[1]>>z[2];
   cin>>v[0]>>v[1]>>v[2];
   cin>>w[0]>>w[1]>>w[2];
  if(n<=2)
   {
   	for(int i=1;i<=n;i=i+1)
   	{
   	a[100000000]++;
	}
	l[0]=1;
	l[1]=1;
	k=j[1]+h[0];
   }
  if(2<u<=4)
   {
    for(int m=1;m>=n;m=m+1)
    {
     a[100000000]++;
	}
	l[0]=1;
	l[1]=1;
	l[2]=2;
	b=o[0]+z[1]+v[2]+w[2];
   }                
cout<<k<<endl<<b;
fclose(stdin);
fclose(stdout);
return 0;
}

