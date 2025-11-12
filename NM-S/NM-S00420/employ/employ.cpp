#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector <int> q[1000005][2];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1,o,p,m;i<=m;i++)
    {
        cin>>o>>p>>m;
        q[i][1].push_back(o);
        q[i][1].push_back(p);
        q[i][2].push_back(m);
    }
    return 0;
}
