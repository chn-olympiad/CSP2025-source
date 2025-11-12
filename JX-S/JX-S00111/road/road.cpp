#include<bits/stdc++.h>
using namespace std;
struct road{
    int u,v,w;
};
int aaaaa;
long long s=0;
road rd[1000005];
bool rr[10001];
bool cmp(road a,road b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>rd[i].u>>rd[i].v>>rd[i].w;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>aaaaa;
        }
    }
    sort(rd+1,rd+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(!(rr[rd[i].u] && rr[rd[i].v])){
            s+=rd[i].w;
            rr[rd[i].u]=true;
            rr[rd[i].v]=true;
        }
    }
    cout<<s;
    return 0;
}
