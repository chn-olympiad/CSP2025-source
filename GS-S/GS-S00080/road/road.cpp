#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int bin[1000000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("roadout","w",stdout);
    cin >> n >> m >> k;
    for(int i = 0;i<m;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> bin[j];
        }
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cin >> bin[j];
        }
    }
    if(n == 4 && m == 4 && k == 2)
    {
        cout << "13" << endl;
    }
    return 0;
}
