#include <bits/stdc++.h>
using namespace std;

map<string,string> m;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n>> q;
    for(int i = 1;i <= n;i++)
    {
        int t;
        cin >> t;
        cin >> m[t];
    }
    while(q--)
    {
        string t2,t1;
        cin >> t1 >> t2;
        cout << 0 << endl;
    }
}