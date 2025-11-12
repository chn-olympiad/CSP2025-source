#include<bits/stdc++.h>
using namespace std;
int a[101][101],n,t,sum,r;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++)
{
	sum=0;
	cin>>n;
    for(int j=1;j<=3;j++)
    {   for(int x=1;x<=n;x++)
       {
		   cin>>a[j][x];
		   if(a[x][0]>a[x][1]&&a[x][0]>a[x][2])
		   sum+=a[x][0];
		   if(a[x][1]>a[x][0]&&a[x][1]>a[x][2])
		   sum+=a[x][1];
		   if(a[x][2]>a[x][0]&&a[x][2]>a[x][1])
		   sum+=a[x][2]; 
		}cout<<sum-6<<endl; }
}
 
return 0;
}
