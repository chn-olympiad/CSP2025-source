#include <bits/stdc++.h>

//RP++
//#Shang4Shan3Ruo6Shui4

using namespace std;

const int MAXN = 1e6 + 5;

string s;

char a[MAXN];
int cnt;

bool cmp(char x, char y)
{
    return x > y;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);


    ios::sync_with_stdio(false);

    cin >> s;

    int len = s.size();

    for(int i = 0; i < len; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a[++cnt] = s[i];
        }
    }

    sort(a + 1, a + 1 + cnt, cmp);

    for(int i = 1; i <= cnt; i++)
    {
        printf("%c", a[i]);
    }


    return 0;
}

