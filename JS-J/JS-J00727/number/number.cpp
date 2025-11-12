#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int m=0;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            m++;
            a[m]=s[i]-'0';
        }
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        cout<<a[i];
    }
    cout<<'\n';
    return 0;
}