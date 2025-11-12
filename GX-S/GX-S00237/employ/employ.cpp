#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int n,m,c[1000010];
string s;
int main()
{
   freopen("employ.in","r",stdin);
   freopen("employ.out","w",stdout);
   cin>>n>>m;
   cin>>s;
   for(int i=1;i<=n;i++)
     cin>>c[i];
   if(s[0]==1){
      cout<<n;
      return 0;
   }
   else{
      int tot=0;
      for(int i=0;i<len.size();i++)
        if(s[i]==1){
          tot=i+1;
          break;
        }
      int cnt=0;
      for(int i=1;i<=n;i++)
        if(c[i]>=tot)
          cnt++;
       cout<<cnt;
       return 0;
   }
   return 0;
}
