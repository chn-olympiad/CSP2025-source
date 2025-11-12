#include<bits/stdc++.h>
using namespace std;
int n;
long long t;
long long x[20006];
long long  o;
int  sum;
int cut;
int  JS=0;
int  b,q,m;
int  g;
int  main()
{
      freopen ("club.in","r",stdin);
    freopen ("club.out","w",stdout);

   cin>>t;
   for(int  i=1;i<=t;i++)
   {
        cin>>n;
        for(int  l=1;l<=n;l++)
        {


        cin>>x[l]>>x[l+1]>>x[l+2];



         sum=max(x[l],x[l+1]);
         cut=max(x[l+1],x[l+2]);
           if(sum>cut)
     {

         o=sum+o;

     }
        else
        {

            o=cut+o;

        }


   }
            cout<<o<<endl;
         o=0;
        }





    return 0;
}

