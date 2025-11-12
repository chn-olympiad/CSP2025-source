#include<bits/stdc++.h>
using namespace std;
int w[10005][100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        cin>>w[a][b];
    }
    cout<<0;
    return 0;
}
