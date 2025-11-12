#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long a[1000003],z=1,l;
    string s;
    cin>>s;
    for(long long i=0; i<s.size(); i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[z]=s[i]-'0';
            z++;
        }
    }
    sort(a+1,a+z-1+1);
    for(long long i=z-1; i>=1; i--)
    {
        cout<<a[i];
    }
    return 0;
}
