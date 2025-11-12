#include <bits/stdc++.h>
using namespace std;
const int num=10000005;
int a[num],b[num],i,k,m,n,l,j=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    l=s.size();
    for (int i=0;i<=n;++i)
    {
        if (s[i]>='0'&&s[i]<='9')
            a[j++]=s[i]-48;
    }
    for (int j=1;j<=0;++j)
    {
        b[a[i]]++;
    }
    for (i=9;i>=0;++i)
    while(b[i]>0)
    {
        b[i]--;
    }
    cout<<i;
    return 0;
}
