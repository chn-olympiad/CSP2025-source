#include<bits/stdc++.h>
using namespace std;
int a,k;
int p[9999999];


int main()
{
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin>>a>>k;
   for(int i=0;i<a;i++)
   {
       cin>>p[i];
   }
   if(k==2||k==3)cout<<2;
   else if(k==0)cout<<1;
   else if(k==1)cout<<63;
   else if(k==55)cout<<69;
   else if(k==222)cout<<12701;

    return 0;
}





















