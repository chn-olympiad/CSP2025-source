#include<bits/stdc++.h>
using namespace std;
int n,m,k,dis[1000006],str[1000005];
struct node{
    int u,v,w;
}a[1000005];
void dig(){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[1] = 0;
    for(int i=1;i<=n;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!str[j]&&(t == -1 || dis[j]<dis[t])){
                t = j;
            }
        }
        for(int j=1;j<=n;j++){
            dis[j] = min(dis[j],dis[t] + a[t].w + j);
        }
    }
    cout<<dis[n];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    dig();
    return 0;
}
