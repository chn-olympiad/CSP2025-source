#include<bits/stdc++.h>
using namespace std;
string a;
int b[12];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]-'0'>=0&&a[i]-'0'<10)
        {
            b[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=b[i];j++)
        {
            cout<<i;
        }
    }
}
