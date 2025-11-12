#include <bits/stdc++.h>
using namespace std;
int x[10];
void duru()
{
    string str;
    cin >> str;
    for(char i: str) if(i>=48&&i<58) x[i-48]++;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    duru();
    for(int i = 9;i+1;i--)
        for(int j = 0;j < x[i];j++)
            cout << i;
    return 0;
}
/*
             o
        OOOOOOOOOOO
    OOOOOOOOOOOOOOOOOOOO
    OO       ·        OO
    OO                OO
    OO  ----   ----   OO
    OO       /        OO
    OO      /_        OO
    OO                OO
    OO     ____       OO
      \______________/
           |    |
      _____|    |_____
     /     \    /     \
     |      \  /      |
     L_______\/_______|
     本人代码写得不好，
     啥都不求，只求能过。
     求求了😢
*/
