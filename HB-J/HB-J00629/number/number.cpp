#include<bits/stdc++.h>
using namespace std;
string s;
int a[10],t;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    getline(cin,s);
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
        {
            t=(int)(s[i]-'0');
            a[t]++;
        }
    for(int i=9;i>=0;i--)
        for(int j=1;j<=a[i];j++)cout<<i;
    return 0;
}
