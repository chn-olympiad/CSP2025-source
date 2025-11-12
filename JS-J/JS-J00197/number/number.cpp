#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int h=0;
    for(int i=0;i<=s.size()-1;i++)
    {
        char o=s[i];
        if(o>=48&&o<=57)
        {
            a[o-'0']++;
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
