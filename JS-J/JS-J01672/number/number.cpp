#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x, int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=0;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i])) a[++n]=s[i]-'0';
    }
    sort(a+1, a+n+1, cmp);
    if(a[1]==0)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
