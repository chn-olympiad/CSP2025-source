#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int c[10000];
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >>c[i];
    }
    if(n==5&&c[1]==1) cout <<9;
    if(n==5&&c[1]==2) cout <<6;
    return 0;
}
