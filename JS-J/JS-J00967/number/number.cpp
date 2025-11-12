#include<bits/stdc++.h>
using namespace std;
int has[20];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
   string s;
   cin>>s;
   //cout<<int(1)-48;
   for(int i=0;i<s.size();i++)
   {
       if(isdigit(s[i])==1)
       {
          has[int(s[i])-48]++;
       }
   }
   for(int i=9;i>=0;i--)
   {
       while(has[i]>0)
       {
           cout<<i;
           has[i]--;
       }
   }
   return 0;
}
