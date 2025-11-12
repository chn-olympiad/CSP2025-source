#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long int n,m,k;
    cin >> n >> m >> k;
    long long int u[m],v[m],w[m];
    for(long long int i = 0;i < m;i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    long long int f[k][n + 1];
    for(long long int j = 0;j < k;j++){
        cin >> f[j][0];
        for(long long int l = 1;l <= n;l++){
            cin >> f[j][l];
        }
    }
    long long int g[n];
    long long int z = 0;
    memset(g,0,sizeof(g));
    for(long long int i = 0;i < n;i++){
        if(g[i] == 0){
            long long int q = 0;
            long long int _min_ = 99999999999999999;
            for(long long int h = 0;h < m;h++){
                if(_min_ > w[h]){
                    if(u[h] == i || v[h] == i){
                        _min_  = w[h];
                        q = h;
                    }
                }
            }
            g[u[q]]++;
            g[v[q]]++;
            z += _min_;

        }
    }
    cout << z << '\n';
    return 0;
}
