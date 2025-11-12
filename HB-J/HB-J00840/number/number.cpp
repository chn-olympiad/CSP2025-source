#include <bits/stdc++.h>
using namespace std;
string s;
int a[10005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int k=1;
    for (int i=0;i<=s.size();i++)
    {
        if (('0'<=s[i]) && (s[i]<='9'))
        {
            a[k]=s[i]-'0';
            k++;
        }
    }
    for (int i=1;i<=k;i++)
    {
        for (int j=i;j<=k;j++)
        {
            if (a[j]>a[i])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for (int i=1;i<k;i++)
    {
        cout<<a[i];
    }
    return 0;
}
