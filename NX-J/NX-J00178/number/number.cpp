#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
  string s,d={};
  cin>>s;
  for(int i=0;i<=s.length()-1;i++)
  {
    if(s[i]>='0'&&s[i]<='9')
    {
      d+=s[i];
    }
  }
    for(int i=0;i<=d.length()-1;i++)
    {
      for(int j=i+1;j<=d.length()-1;j++)
    {
       if(d[i]<d[j])
       {
         swap(d[i],d[j]);
       }
    }
  }
  for(int i=0;i<=d.length()-1;i++)
  {
    cout<<d[i]-'0';
  }
  return 0;
}
