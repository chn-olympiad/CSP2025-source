#include <bits/stdc++.h>
using namespace std;
int counnt;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int sum=0;
  string s;
  cin>>s;
  long long h[1000000]={0};
   for(int a=0;a<=s.size();a++)
  {
      if(s[a]>='0'&&s[a]<='9')
      {
          counnt++;
        h[a]=int(s[a]-48);
      }
  }
  sort(h,h+1000000+1);
  for(int a=1000000;a>=0;a--)
  {   if(counnt==0)
      {
          break;
      }
      counnt--;
      cout<<h[a];
  }
  return 0;
}
