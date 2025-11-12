#include<bits/stdc++.h>
using namespace std;
int a[5000][5000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int x =1,y=1;
    for(int i = 1;i<=n;i++)
    {
        for(int j = i+1;j<=m;j++)
        {
            if(a[i][j]>a[x][y])
            {
                x = i;
                y = j;
            }
        }
    }
    cout<<x<<" "<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

