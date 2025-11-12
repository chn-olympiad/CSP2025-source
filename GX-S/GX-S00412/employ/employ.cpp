#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n, m, l, sum = 0;
    string s;
    cin >> n >> m >> s;
    for(int i = 0; i < n; i++)
    {
        cin >> l;
        if(l!=0) sum++;
    }
    for(int i = sum - 1; i > 1; i--)
    {
        sum *= i;
    }
    cout << sum % 998 % 244 % 353;
    return 0;
}
