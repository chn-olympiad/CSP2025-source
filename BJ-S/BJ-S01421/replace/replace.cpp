#include <bits/stdc++.h>
using namespace std;
struct stu
{
    string a , b;
    bool f;
} x[200010];
int main()
{
    freopen("repalce.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);
    int n , q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i].a >> x[i].b;
    }
    for(int i = 1; i <= q; i++)
    {
        string s1 , s2;
        cin >> s1 >> s2;
        if(s1.size() != s2.size())
        {
            cout << 0 << endl;
            continue;
        }
        cout << 0 << endl;
    }
    return 0;
}
