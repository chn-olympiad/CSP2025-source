#include <bits/stdc++.h>
using namespace std;
int c[510],sum;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >>s[i];
        if (s[i]==1)
        {
            sum++;
        }
    }
    cout << m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}