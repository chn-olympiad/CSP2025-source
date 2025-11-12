#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string s;
int a[15];

void s2i(string s, int a[])
{
    for (int i = 0;i < s.size();i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            a[s[i] - '0']++;
    }
    return;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    s2i(s,a);
    for (int i = 9;i >= 0;i--)
    {
        while (a[i]--)
        {
            printf("%d",i);
        }
    }
    printf("\n");
    return 0;
}
