#include<bits/stdc++.h>
using namespace std;
long long mc=0,r,n,m,a[10000001],b[101][101],sz=1;
bool cmp(long long a,long long b)
{

    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>r;
    a[1]=r;
   for(long long i=2;i<=n*m;i++)
   {
       cin>>a[i];
   }
   sort(a+1,a+1+n*m,cmp);
   for(long long i=1;i<=n*m;i++)
   {
       if(a[i]==r)
       {
           mc=i;
           break;
       }

   }
   long long sx=1,zy=1;
   while(zy<=m)
   {
       long long nn;
       if(sx==1) nn=1;
       if(sx==-1) nn=n;
       for(long long j=1;j<=n;j++)
       {

           if(sx>0)b[nn+sx-1][zy]=sz;
           else b[nn+sx+1][zy]=sz;
           sz++;


          if(sx>0) sx++;
          else sx--;
       }
       zy++;
      if(sx>0) sx=-1;
      else sx=1;
   }
   for(long long i=1;i<=n;i++)
   {

       for(long long j=1;j<=m;j++)
       {

           if(b[i][j]==mc) cout<<i<<" "<<j;

       }
   }

     return 0;
}
