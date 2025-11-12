#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m,k,a[10002][10002],maxx=-1,v[10002],s[10002][10002];
vector<int> d[maxn];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,s;
        cin>>u>>v>>s;
        d[u].push_back(v);
        d[v].push_back(u);
        a[u][v]=s;
        a[v][u]=s;
        maxx=max(maxx,s);
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
        for(int j=1;j<=m;j++)
            cin>>s[i][j];
    }
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==maxx)
                continue;
            else{
                sum+=a[i][j];
            }
        }
    }
    cout<<sum;
    return 0;
}
