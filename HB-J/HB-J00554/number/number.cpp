#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen(number.in,"r",stdin);
freopen(number.out,"w",stdout);
int n=0;
cin>>n;
char s[10000005];
for(int i=1;i<=s.sight(s);i++)
{
cin>>s[i];
}
int m=s.sight(s);
cin>>m;
int a[m];
for(int i=1;1<=m;i++)
{
    cin>>a[i];
}
if(m==1)
{
cout<<s[0];
}
else
{
  for(int i=1;i<=n;i++)
  {
   if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
   {
    n++;
   }
  }
  for(int i=1;i<=n;i++)
  {
   if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
   {
    a[i]==s[i];
   }
  }
  sort(a+1,a+n+1);
  for(int i=m;i>=n-1;i++)
  {
          cout<<a[i];
  }
}
return 0;
}
