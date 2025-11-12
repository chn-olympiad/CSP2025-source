#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("employ.in",r)
freopen("employ.ans",w)
int n,m,s,c,p;
cin>>n>>p>>m;
for(int i=1;i<=n;i++)
{
   if(s==0)
        n--;
   else
        m++;
   for(int j=1;j<=m;j++)
   {
        if(c<m)
              n--;
   }
}
cout<<m*p%998244353<<" ";
return 0;
}
