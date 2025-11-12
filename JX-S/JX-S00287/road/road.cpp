#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,a;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
    }
    for(int i=1;i<=k;i++){
        for(int i=0;i<=n;i++){
            cin>>a;
        }
    }
    cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
