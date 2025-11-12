#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    const char endl = '\n';
    ios::sync_with_stdio(false);
    cin.tie();

    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a[cnt++] = s[i] - '0';
        }
    }

    for(int i = 0; i < cnt; i++)
    {
        for(int j = i + 1; j < cnt; j++)
        {
            if(a[i] < a[j]) swap(a[i], a[j]);
        }
    }


    for(int i = 0; i < cnt; i++)
        cout << a[i];

}
