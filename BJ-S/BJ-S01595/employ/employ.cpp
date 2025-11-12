#include<bits/stdc++.h>
using namespace std;

int n, m, n1[505], sum;
string s;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= m; i++)
    {
        cin >> n1[i];
        sum *= n1[i];
    }
    cout << sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
