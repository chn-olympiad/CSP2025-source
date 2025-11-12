#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[i]=s[i];
        }
    }
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s.size();j++)
        {
            if(a[j]>=a[i])
            {
                int n=a[i];
                a[i]=a[j];
                a[j]=n;
            }
        }
        cout<<a[i];
    }
    return 0;
}
