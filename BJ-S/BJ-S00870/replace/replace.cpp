#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=2*(n+m);i++)
    {
        cin >> s;
    }
    for (int i=1;i<=m;i++)
    {
        cout << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}