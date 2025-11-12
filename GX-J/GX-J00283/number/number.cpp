#include<bits/stdc++.h>
using namespace std;

char a[1010];
char s[1010];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0; i < 1010; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a[i] = s[i];
        }
        else
        {
            contiue;
        }
    }
    cout << a;
    return 0;
}
