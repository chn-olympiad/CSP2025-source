#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int a[MAXN];
int p=0;
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
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[p]=s[i]-'0';
            p++;
        }
    }
    sort(a,a+p,cmp);
    for(int i=0;i<p;i++)
    {
        cout<<a[i];
    }
    return 0;
}
