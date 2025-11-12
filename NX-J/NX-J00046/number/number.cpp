#include<bits/stdc++.h>
using namespace std;
int shu[20000005];
int main()
{
    string s;
    string s1;
    int a=0,b=0,c=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a++;
            shu[a]=s[i]-'0';
        }
    }
 //   for(long long i=0;i<=a;i++)
  //  {
    //    for(long long j=1;j<=a-i;j++)
   //     {
  //          if(shu[j]<shu[j+1]) swap(shu[j],shu[j+1]);
  //      }
  //  }
  sort(shu+1,shu+a+1);
    for(long long i=a;i>=1;i--)
    {
        cout<<shu[i];
    }
    return 0;
}
