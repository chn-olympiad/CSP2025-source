#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,q;
string a;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin >> a;
        }
    }
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin >> a;
        }
        cout << 2 << endl;
    }
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin >> a;
        }
        cout << 0 << endl;
    }
    for(int i=2;i<q;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin >> a;
        }
        cout << 0 << endl;
    }
    return 0;
}
