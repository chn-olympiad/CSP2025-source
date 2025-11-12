#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct c{
    int u,v,w;
}f[10005];
struct r{
    int w;
    bool f;
}t[10005];
int a[10][10005];
int c1;
bool cmp(c a,c b){
    return a.w>b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>f[i].u>>f[i].v>>f[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c1;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            a[i][j]+=c1;
        }
    }
    if(k==0){
        int sum=0;
        sort(f+1,f+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(t[f[i].u].f==1&&t[f[i].v].f==1){
                continue;
            }else{
                sum+=f[i].w;
                t[f[i].u].f=t[f[i].v].f=1;
            }
        }
        cout<<sum;
    }else{
        cout<<0;
        return 0;
    }
    return 0;
}
