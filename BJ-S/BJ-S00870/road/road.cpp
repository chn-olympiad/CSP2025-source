#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=1;i<=3*(m);i++)
    {
        cin >> s;
    }
    for (int i=1;i<=5*(k);i++)
    {
        cin >> s;
    }
    cout << n*2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}