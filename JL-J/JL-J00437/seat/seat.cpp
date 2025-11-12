#include <bits/stdc++.h>
using namespace std;

int main()
{freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long n,m;
cin >> n >> m;
int g[m*n];
for(int i=1;i<=m*n;i++)
    cin >> g[i];
    int h=g[1];
int seat[m][n];
for(int i=0;i<=n*m;i++)
{
    int b=g[0];
    if(g[i]>=b) b=g[i];
    g[i]=b;
}
for(int i=0;i<=n;i++)
{

    for(int j=0;j<=m;j++)
    {

        for(int k=i;k<=n*m;k++)
        {
            seat[j][i]=g[k];
        }
    }
}
for(int i=0;i<=n;i++)
{

    for(int j=0;j<=m;j++)
    {
        if(seat[j][i]==h) cout << seat[j][i];
    }
}
return 0;
}
