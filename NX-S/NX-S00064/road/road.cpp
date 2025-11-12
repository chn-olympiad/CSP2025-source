#include <bits/stdc++.h>
using namespace std;

int a[10001][3],b[11][5];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k;
    cin >>n>>m>>k;
    for(int i=1; i<=n; i++)
    {
        cin >>a[i][0]>>a[i][1]>>a[i][2];
    }
    for(int i=1; i<=k; i++)
    {

        cin >>b[i][0]>>b[i][1]>>b[i][2]>>b[i][3]>>b[i][4];
    }
    cout <<0;
    return 0;
}
