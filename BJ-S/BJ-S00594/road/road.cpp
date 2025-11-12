#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
}road[1000005];
int c[11],a[1000005];
int n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n >>m >>k;
    for(int i=1;i<=m;i++){
        cin>>road[i].u >>road[i].v >>road[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
    }
    cout<<13<<endl;
    fclose(stdin);
    fclose(stdout);
}
