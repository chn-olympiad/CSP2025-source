#include<bits/stdc++.h>
using namespace std;
long long a[1000005]={0};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
   string s;
   cin>>s;
   int n=0;
   if(s.size()==1)
   {
       cout<<s;
   }
   else
{
    for(int i=0;i<s.size();i++)
       {
           if(s[i]>='0'&&s[i]<='9')
           {
               a[i]=s[i];
               n++;
           }
       }
       sort(a+1,a+1+n);
       for(int i=1;i<=n;i++)
       {
           cout<<a[i];
       }
}

   return 0;
}
