#include<bits/stdc++.h>
using namespace std;
string s;
int a[20];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    memset(a,0,sizeof(a));
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=1;i<=s.size();i++)
    {
        if(s[i-1]>='0'&&s[i-1]<='9')
        {
            a[s[i-1]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            cout<<i;
        }
    }
    cout<<'\n';
    return 0;
}
