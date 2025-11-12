#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
long long luvia;
long long u,v,w;
int main()
{

    //freopen("club.in", "r", stdin);
    //freopen("club.out", "w", stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        luvia+=w;
    }
    cout<<luvia;
    return 0;
}
