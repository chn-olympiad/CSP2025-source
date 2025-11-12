#include<bits/stdc++.h>
using namespace std;
int t[11][11],sum=1;
int a[10000];
int main()
{freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {

        cin>>a[i];
    }
 int q=a[1];
 for(int i=1;i<=n*m;i++)
  for(int j=i+1;j<=n*m;j++)
    {

        if(a[j]>a[i])
        {

            swap(a[j],a[i]);
        }
    }

for (int i=1;i<=m;i++)
{if(i%2==1){
    for(int j=1;j<=n;j++)
   {
       t[i][j]=a[sum];
       if(t[i][j]==q)
       {

           cout<<i<<" "<<j<<endl;
           return 0;
       }
       sum++;

   }
       }else{
           for(int j=n;j>=1;j--)
           {

            t[i][j]=a[sum];
             if(t[i][j]==q)
       {

           cout<<i<<" "<<j<<endl;
           return 0;
           }
         sum++;

       }

}}
return 0;
}
