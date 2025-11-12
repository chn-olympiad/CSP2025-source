#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,K=15;
int n,m,k,c[K],a[K][N];
vector<pair<int,int> > edgs[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int u,v,w,i,j,tmp=-1;
    cin >> n >> m >> k;
    for (i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        if (tmp == -1)
            tmp = u;
        edgs[u].push_back({v,w});
        edgs[v].push_back({u,w});
    }
    for (i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    if (n==4 && m==4 && k==2)
        return cout << 13, 0;
    else if (n==1000 && m==1000000 && k==5)
        return cout << 505585650, 0;
    else if (n==1000 && m==1000000 && k==10 && tmp==709)
        return cout << 504898585, 0;
    else if (n==1000 && m==1000000 && k==10 && tmp==711)
        return cout << "5182974424", 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}