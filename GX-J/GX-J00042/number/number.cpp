#include<iostream>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    int tj=0;
    string s;
    cin>>s;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
            tj++;
    }
    char a[tj];
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
            a[i]=s[i];
    }
    for(int i=0;i<=s.size();i++)
    {
        for(int j=0;j<=s.size();j++)
        {
            if(a[j]<a[j+1])
                swap(a[j],a[j+1]);
        }
    }
    for(int i=0;i<=s.size();i++)
    {
        cout<<a[i];
    }
    return 0;
}
