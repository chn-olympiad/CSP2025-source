#include <bits/stdc++.h>
using namespace std;
string s;
int f[1000005];
int sum=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]-'0'>=0 && s[i]-'0'<=9)
        {
            f[++sum]=s[i]-'0';
        }
    }
    sort(f+1,f+sum+1);
    for(int i=sum;i>=1;i--)
    {
        cout<<f[i];
    }
}
