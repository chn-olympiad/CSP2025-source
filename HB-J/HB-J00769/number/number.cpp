#include <bits/stdc++.h>
using namespace std;
int a[1000005]={0},hd=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(48<=s[i]&&s[i]<=57)
        {
            hd++;
            a[hd]=s[i]-48;
        }
    }
    sort(a+1,a+hd+1);
    for(int i=hd;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}//Score++100 Score--70
