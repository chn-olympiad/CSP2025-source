#include <bits/stdc++.h>
using namespace std;
string why_bilibili;//you can search him on luogu
const int Max = 1e6+5;//interesting,isn't it?
int fly[Max], eagle = 0;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> why_bilibili;
    int ciallo = why_bilibili.length();
    for(int bro = 0;bro < ciallo;bro++)
    {
        if(isdigit((why_bilibili[bro])))
            fly[++eagle] = why_bilibili[bro]-'0';
    }
    sort(fly+1, fly+eagle+1);
    for(int maki = eagle;maki > 0;maki--)
        cout << fly[maki];
    return 0;
}
