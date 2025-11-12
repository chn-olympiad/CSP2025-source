#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long a[N],n,p=1;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
   cin>>s;
   long long len=s.size();
   for(long long i=0;i<len;i++)
   {
   if(s[i]>='0'&&s[i]<='9')
     {
        a[p]=s[i]-'0';
        p++;
     }
   }
   sort(a+1,a+p+1);
   for(long long i=p;i>1;i--)
   {
      cout<<a[i];
   }
   return 0;
}
