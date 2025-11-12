#include <bits/stdc++.h>
using namespace std;
string a,b,s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<=n;j++)
        {
           if(a[i]<a[j])
           {
               b[i]=a[i];
               a[i]=a[j];
               a[j]=b[i];
           }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }


    return 0;
}
