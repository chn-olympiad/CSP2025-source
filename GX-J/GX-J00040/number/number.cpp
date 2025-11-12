#include <bits/stdc++.h>
using namespace std;

int a[10];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

   string s;
   cin>>s;
   for(int i=0;i<s.size();i++)
   {
        if(s[i]-'0'<10 && s[i]-'0'>=0)  a[s[i]-'0']++;
   }
   for(int i=9;i>-1;i--)
   {
       while(a[i]>0)
       {
           cout<<i;
           a[i]--;
       }
   }
   cout<<endl;
   return 0;
}
