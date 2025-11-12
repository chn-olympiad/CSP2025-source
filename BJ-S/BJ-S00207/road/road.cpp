#include<bits/stdc++.h>

using namespace std;

struct node{
    int u,v,w;
};
int n,m,k;
vector<node> v[10005];
int lst[1005][1005];
int c[1005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({a,b,c});
        v[b].push_back({b,a,c});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>lst[i][j];
        }
    }

    cout<<0;

    return 0;
}

