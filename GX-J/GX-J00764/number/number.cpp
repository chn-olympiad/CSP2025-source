#include<bits/stdc++.h>
using namespace std;
long long a[1002];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    long long m=0;
    for(long long i=0; i<s.size(); i++)
    {
        if(s[i]<=9&&s[i]>=0)
        {
            a[i]=s[i];
            m++;
        }

    }
    sort(a,a+1000);
    for(long long i=0; i<=m; i++)
    {
        cout<<a[i];
    }
    return 0;
}
