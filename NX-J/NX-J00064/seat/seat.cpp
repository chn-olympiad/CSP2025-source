#include <bits/stdc++.h>
using namespace std;
int a[10000][10000];
int n,m;
bool cmp(int x,int y)
{
    return x>y; 
}

int main()
{
    freopen("seat.in","r",stdin);
    frepoen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;i<=m;i++)
        {
            cin >> a[i][j];
            
        }
    }
    sort(a[1][1],a[n][m],cmp);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            
            cout << a[i][j];
        }
    }
}