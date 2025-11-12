#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll u,v,w;
}a[999999]={};
ll n,m,cnt=1,ans=0;
ll h[999999]={};
ll p[999999]={};
bool cmp(node a,node b){
    return a.w<b.w;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;++i){
        cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
    }
    ans+=a[1].w;
    h[a[1].u]++;
    h[a[1].v]++;

    for(int i=2;i<=m;++i){
        if(cnt==n-1)break;
        if(h[a[i].v]>=2&&h[a[i].u]>=2){
           continue;
        }
        cnt++;
        cout<<a[i].v<<" "<<a[i].u<<endl;
        h[a[i].u]++;
        h[a[i].v]++;

        ans+=a[i].w;
    }
    cout<<ans;
    return 0;
}
