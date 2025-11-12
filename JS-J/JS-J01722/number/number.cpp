#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

char s[1000005];
int tot = 0;
int t[1000005];

bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;s[i] != '\0';i++)
    {
        if(s[i] <= '9' && s[i] >= '0')
        {
            tot++;
            t[tot] = s[i] - '0';
        }
    }
    sort(t + 1,t + 1 + tot,cmp);
    for(int i = 1;i <= tot;i++)
    {
        cout << t[i];
    }
    return 0;
}
