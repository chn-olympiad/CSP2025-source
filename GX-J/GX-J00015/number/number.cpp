#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[s.size()];
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=int(s[i])-48;
        }
        if(s[i]>='a'&&s[i]<='z')
        {
            a[i]=10;
        }
    }
    for(int i=0;i<s.size()-1;i++)
    {
        for(int j=0;j<s.size();j++)
        {

            if(a[j]<a[j+1])
            {
                int h=a[j];
                a[j]=a[j+1];
                a[j+1]=h;
            }
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(a[i]<=9)
        {
            cout<<a[i];
        }
    }
    return 0;
}
