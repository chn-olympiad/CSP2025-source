#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[10],a[10];
    int maxn=0;
    for(int i=1;i<=10;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=10;i++)
    {
        if(s[i]>=1&&s[i]<=9)
        {
            a[i]+=s[i]*10;
        }
    }

    for(int i=1;i<=10;i++)
    {
        if(a[i]>maxn)
        {
            maxn=a[i]
        }
        else
        {
            s[i]+=a[i]/10;
            a[i]=s[i];
        }
    }
    cout<<a[i];
    return 0;
}

