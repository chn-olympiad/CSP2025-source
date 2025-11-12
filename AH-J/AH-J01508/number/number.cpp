#include<bits/stdc++.h>
using namespace std;
string s,d;
int i,j,n,a,f;
int main()
{
 freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
 cin>>s;
 n=s.size();
 for(i=1;i<=n;i++)
 {
  if(s[i]>='0'&&s[i]<='9')
  {
   d[i]=s[i];
   a++;
  }
 }
 for(i=1;i<=n;i++)
 {
  for(j=i;j<=n;j++)
  {
   if(d[i]<d[j])
   {
    swap(d[i],d[j]);
   }
  }
 }
 for(i=1;i<=n;i++)
 {
  cout<<d[i];
 }
 return 0;
}
