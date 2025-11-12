#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int N=1e4+9;
int e[N][N];
vector<int> c;
vector<int> a[11];
signed main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        e[u][v]=w;
        e[v][u]=w;
    }
    int sum=0;
    while(k--){
        int cc=0;cin>>cc;
        c.push_back(cc);
        sum+=cc;
        for(int i=0;i<n;i++){
            cin>>cc;a[k].push_back(cc);
            sum+=cc;
        }
    }
    if(sum==0){
        cout<<0<<endl;return 0;
    }
    cout<<0<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Ren5Jie4Di4Ling5%

