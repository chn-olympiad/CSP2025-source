#include <bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    char c;
    while(cin>>c)
    {
        int x=(int)c-48;
        a[x]++;
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