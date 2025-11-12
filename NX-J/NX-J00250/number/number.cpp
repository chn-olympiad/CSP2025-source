#include<bits/stdc++.h>
using namespace std;
long long sh[1000005];
int main()
{
    freopen("number.in", "r",stdin);
    freopen("number.out", "w",stdout);
    string s;
    cin>>s;
    string s1;
    for (long long i=0;i<s.size();i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            s1+=s[i];
        }
    }
    long long n=s1.size();
    for (long long i=0;i<n;i++)
    {
        sh[i+1]=s1[i]-48;
    }
    sort(sh+1,sh+n+1);
    for (long long i=n;i>=1;i--)
    {
        cout<<sh[i];
    }
    return 0;
}
