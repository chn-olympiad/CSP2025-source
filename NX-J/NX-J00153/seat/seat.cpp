#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            s=a[1];
        }
    }
    for(int i=1;i<=n*m-1;i++)
   {
       for(int j=1;j<=n*m-i;j++)
       {
           if(a[j]<a[j+1])
           {
               swap(a[j],a[j+1]);
           }
       }
   }
   int p=1;
   for(int i=1;i<=n*m;i++)
   {
       if(a[i]==s)
       {
           p=i;
       }
   }

   int c=1,r=0;
   for(int i=1;i<=p;i++)
   {
        if(r+1>n&&c%2==1)
        {

            r=n;

            c++;

        }
        else if(r-1<1&&c%2==0)
        {

            r=1;

            c++;
        }
        else
        {
             if(c%2==0)
           {
               r--;

           }
           else
           {
               r++;

           }
        }



        //cout<<c<<" "<<r<<endl;
   }

   cout<<c<<" "<<r;
   return 0;
}
