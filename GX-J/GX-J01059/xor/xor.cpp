#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    char a[1001],b=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i];
        }
    }
    for(int i=0;i<s.size()-1;i++)
    {
        for(int j=i+1;j<s.size();j++)
        {
            if(a[i]>='0'&&a[i]<='9'&&a[j]>='0'&&a[j]<='9'&&a[j]>a[i])
            {
                b=a[j];
                a[j]=a[i];
                a[i]=b;
            }
        }
    }
    for(int i=0;i<s.size();i++)
    {
        cout<<a[i];
    }
    return 0;
}
