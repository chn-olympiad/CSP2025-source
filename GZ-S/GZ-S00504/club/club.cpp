//GZ-S00504 πÛ—Ùæ≈÷– ª∆÷æ∫Ω 
#include<bits/stdc++.h>
using namespace std;
int x[5];
int y[5];
int main()
{
 freopen("club.in","r",stdin);
 freopen("club.out","w",stdout);
 int t;
 cin>>t;
 for(int h=1;h<=t;h++)
 {
  int n;
  x[1]={0};
  x[2]={0};
  x[3]={0};
  y[1]={0};
  y[2]={0};
  y[3]={0};
  int ans=0;
  cin>>n;
  int a[n+5][5];
  int maxn[n+5],maxi[n+5];
  for(int i=1;i<=n;i++)
  {
   cin>>a[i][1]>>a[i][2]>>a[i][3];
   if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
   {
    maxn[i]=a[i][1];
    maxi[i]=1;
   }
   if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])
   {
    maxn[i]=a[i][2];
    maxi[i]=2;
   }
   if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
   {
    maxn[i]=a[i][3];
    maxi[i]=3;
   }
  }
  for(int j=1;j<=3;j++)
  {
   while(x[j]<n/2)
   {
   	int s=0,z=0;
    for(int i=1;i<=n;i++)
    {
     if(maxi[i]==j&&maxn[i]>=s)
     {
      s=maxn[i];
      z=i;
 	 }
    }
    if(s==0) 
	{
	 break;
	}
    else
    {
     ans+=s;
     maxn[z]=0;
     x[j]++;
	}
   }
   if(x[j]==n/2)
   {
    y[j]=1;
   }
  }
  if(y[1]+y[2]+y[3]==1)
  {
   for(int i=1;i<=n;i++)
   {
    if(maxn[i]>=0)
    {
     a[i][maxi[i]]=-1;
   	 int b=0;
     for(int j=1;j<=3;j++)
      max(b,a[i][j]);
     ans+=b;
    } 
   }
  }
  cout<<ans<<endl;
 }
 return 0;
}
