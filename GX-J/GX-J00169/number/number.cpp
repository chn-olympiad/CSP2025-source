#include<bits/stdc++.h>
using namespace std;
string s;
int a[9999990];
int g=0,f;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(int(s[i])<65)
        {
           a[g]=int(s[i])-48;
           g++;
        }

    }
     for(int i=0;i<g;i++)
     {
          for(int j=0;j<g-1;j++)
     {
         if(a[j]<a[j+1])
         {
             f=a[j];
             a[j]=a[j+1];
             a[j+1]=f;
         }
     }
     }

          for(int j=0;j<g;j++)
     {
         cout<<a[j];
     }
    return 0;
}
