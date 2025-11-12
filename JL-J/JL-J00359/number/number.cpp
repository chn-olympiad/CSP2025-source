#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    string a;
    int b=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[b]=s[i];
            b++;
        }
    }
    for(int i=0;i<b;i++)
    {
       for(int j=0;j<b-1;j++)
       {
           if(a[j]<a[j+1])
           {
               swap(a[j],a[j+1]);
           }
       }
    }
    for(int i=0;i<b;i++)
    {
        cout<<a[i];
    }
    return 0;
}
