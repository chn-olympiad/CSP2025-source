#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int l;
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            a[int(s[i])-int('0')]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}