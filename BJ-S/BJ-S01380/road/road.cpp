#include <bits/stdc++.h>
using namespace std;
int sum;
int n,m,k;
struct Node{
    int v;
    int w;
}a[10009];
int mp[11][10009];
int f[10009];
int find(int k){
    if(f[k] ==k)return k;
    return f[k] = find(f[k]);
}
bool cmp(Node A,Node B){
    return  A.w<B.w;
}
bool check(){
    for(int i=1;i<=n-1;i++){
            if(find(i)!=find(i+1))return 0;
    }
    return 1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >>n >> m>> k;
    for(int i=1;i<=m;i++){
        int v,u,w;
        cin >>v>>u>>w;
        a[v]={u,w};
        a[u]={v,w};
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++)cin >> mp[i][j];
    }
    for(int i=1;i<=n;i++)f[i] = i;
    sort(a+1,a+n+1,cmp);
    int ss = 1;

    while(!check()){
        if(find(a[ss].v) != find(ss)){
            f[a[ss].v] = ss;
            sum += a[ss].w;
            ss++;
        }
    }
    cout <<sum;
    return 0;
}
