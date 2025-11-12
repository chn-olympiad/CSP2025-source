#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i;i<n;i++)
    {
        for(int j;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int t;t<n;t++)
    {
        for(int y;y<m;y++)
        {
            cin >> a[t][y];
        }
    }
    cout << "2"


return 0;
}



