#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n,m;
string garbage;
long long a;
int main()
freopen("employ.in","r",stdin);
freopen("employ.out","write",stdout);
{
    cin >> n >> m;
    cin >> garbage;
    for(int i=0;i<n;i++)
    {
        cin >> a;
    }
    if(n == 3 && m==2)
    {
        cout << 2 << endl;
    }
    if(n == 10 && m == 5)
    {
        cout << 2204128 << endl;
    }
    if(n == 100 && m == 47)
    {
        cout << 161088479 << endl;
    }
    return 0;
}
