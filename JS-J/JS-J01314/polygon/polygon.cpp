#include <bits/stdc++.h>
using namespace std;
struct w
{
    char* in()
    {
        return "polygon.in";
    }
    char* out()
    {
        return "polygon.out";
    }
}polygon;
char* r = "r", *w="w";
FILE * dsbin=stdin;
FILE * dsbout=stdout;
#define din cin
#define dout cout
int main()
{
    freopen(polygon.in(),r,dsbin);
    freopen(polygon.out(),w,dsbout);
    int s;
    din >> s;
    for(int i = 3;s-i+1;i++)
    {
        s++;
    }
    cout << s;
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