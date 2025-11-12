#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen£¨"polygon.in","r",stdin£©;
    freopen("polygon.out","w",stdout);
  int a;
  cin>>a;
  int arr[199],m=0;
  for(int i=0;i<a;i++)
  {

      cin>>arr[i];
  }
   for(int i=0;i<a;i++)
   {
       for(int j=1;j<a;j++)
       {
           for(int h=2;h<a;h++)
           {
               if(arr[i]+arr[j]++arr[k]>2*max(arr[i],arr[j],arr[h]))
               {
                   m++;

               }

           }

       }

   }
   for(int i=0;i<a;i++)
   {
       for(int j=1;j<a;j++)
       {
           for(int h=2;h<a;h++)
           {
               for(int g=3;g<a;g++)
               {
                   if(arr[i]+arr[j]+arr[h]+arr[g]>2*max(arr[i],arr[j],arr[h],arr[g]))
                   {
                       m++;

                   }
               }

           }

       }

   }
 for(int i=0;i<a;i++)
   {
       for(int j=1;j<a;j++)
       {
           for(int h=2;h<a;h++)
           {
               for(int g=3;g<a;g++)
               {
                  for(int k=4;k<a;k++)
                  {
                     if(arr[i]+arr[j]+arr[h]+arr[g]+arr[k]>2*max(arr[i],arr[j],arr[h],arr[g],arr[k]))
                   {
                       m++;

                   }

                  }
               }

           }

       }

   }
   for(int i=0;i<a;i++)
   {
       for(int j=1;j<a;j++)
       {
           for(int h=2;h<a;h++)
           {
               for(int g=3;g<a;g++)
               {
                  for(int k=4;k<a;k++)
                  {
                     for(int y=5;y<a;y++)
                     {
                          if(arr[i]+arr[j]+arr[h]+arr[g]+arr[k]+arr[y]>2*max(arr[i],arr[j],arr[h],arr[g],arr[k],arr[y]))
                   {
                       m++;

                   }

                     }

                  }
               }

           }

       }

   }
   for(int i=0;i<a;i++)
   {
       for(int j=1;j<a;j++)
       {
           for(int h=2;h<a;h++)
           {
               for(int g=3;g<a;g++)
               {
                  for(int k=4;k<a;k++)
                  {
                     for(int y=5;y<a;y++)
                     {
                         for(int t=6;t<a;t++)
                         {

                          if(arr[i]+arr[j]+arr[h]+arr[g]+arr[k]+arr[y]+arr[t]>2*max(arr[i],arr[j],arr[h],arr[g],arr[k],arr[y],arr[t]))
                   {
                       m++;

                   }
                         }
                     }

                  }
               }

           }

       }

   }
   cout<<m;
    fclose(stdin);
    fclose(stdout);

    return 0;
}

