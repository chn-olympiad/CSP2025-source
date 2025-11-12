#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],b[100001],c[100001],zm,t,ar,br,cr,aa;
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++){
        zm=0;
  long long n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
      cin>>a[i]>>b[i]>>c[i];
  }
   if(b[1]==0&&c[1]==0)
   {
       sort(a,a+n+1);
       for(int i=n;i>=n/2;i--)
       {
           zm+=a[i];
       }
       cout<<zm;

   }
   if(c[1]==0)
   {
       for(int i=1;i<=n;i++)
       {
           zm+=max(a[i],b[i]);
       }
       cout<<zm<<endl;

   }
}
cout<<zm;
return 0;
}
