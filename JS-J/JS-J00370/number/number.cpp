#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
   string s;
   int a[1000005],cnt = 0;
   cin >> s;
   for(int i = 0;i<s.length();i++)
   {
       if(s[i] >= '0' && s[i] <='9')
            a[++cnt]=(s[i] - '0');
   }
   string ans;
   sort(a+1,a+cnt+1,cmp);
   for(int i = 1;i<=cnt;i++)
   {
       cout << a[i];
   }
   return 0;
}
