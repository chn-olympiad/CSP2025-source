#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;char a[10001];int n=0,m=10;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z')i=i;
        else
        {
            a[n]=s[i];
            n++;
        }
    }
    for(int i=0;i<=9;i++)
    {
        m--;
        for(int j=0;j<n;j++)
        {
            if(int(a[j])-'0'==m)
            {
                cout<<a[j];
                a[j]=NULL;
            }
        }
    }
    return 0;
}
