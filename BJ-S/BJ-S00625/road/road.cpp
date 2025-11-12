#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<long long>g[200045],d[200045];
bool vis[200055];
long long sum = 0;
long long n;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","r",stdout);
    long long m,k;
    cin >>n >>m >>k;
    for (int i = 1;i<=m;i++){
        long long u,v,w;
        cin >> u >>v >>w;
        g[u].push_back(v);
        d[u].push_back(w);
        g[v].push_back(u);
        d[v].push_back(w);

    }
    for (int i = 1;i<=k;i++){
        int c;
        cin >>c;
        long long x[20005];
        for (int j = 1;j<=n;j++){
            cin >> x[j];
        }
        for (int j = 1;j<=n;j++){
            for (int l = j+1;l<=n;l++){
                g[l].push_back(j);
                d[l].push_back(0ll+x[l]+x[j]+c);
                g[j].push_back(l);
                d[j].push_back(0ll+x[l]+x[j]+c);
            }

        }

    }

    for (int i = 1;i<n;i++){
        int minn = 2e9;
        long long v;
        for (int j = 0;j<g[i].size();j++){
            //if (vis[i]&&vis[j])continue;
            v = d[i][j];

            if (v<minn){
                vis[i] = vis[j] = 1;
                minn = v;
            }
        }
       sum+=minn;
    }

    cout <<sum;
    return 0;
}
