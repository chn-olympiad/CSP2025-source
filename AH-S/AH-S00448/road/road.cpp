#include<bits/stdc++.h>
using namespace std;
struct ro{
    int u,v,w;
}a[10005];
int s[505][505];
bool cmp(ro a,ro b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+1+m,cmp);
    int ans=0;
    for(int i=1;i<n;i++){
        ans=ans+a[i].w;
    }
    cout<<ans;
    return 0;
}
