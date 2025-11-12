#include<bits/stdc++.h>
using namespace std;

int n,m,k,c,u,y,w,s=0;
int a[10001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>y>>w;
        s+=w;
    }
    for(int i=1;i<=k;i++){
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
    }
    cout<<s;
    return 0;
}
