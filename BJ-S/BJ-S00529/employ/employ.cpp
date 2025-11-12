#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
void spew(const char* c)
{
    for(int i=strlen(c)-1;i>=0;i--)
        ungetc(c[i],stdin);
}
int main()
{
    int n;
    spew("114");
    spew("456");
    cin >> n;
    cout << n;
    return 0;
}
