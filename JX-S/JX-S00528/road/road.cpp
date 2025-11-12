#include <bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
}a[1027000];
bool cmp(A n,A d){
    return n.w<d.w;
}
int bcg[102700];
vector <int>c[13];
int ca[13];
int bcj(int n){
    if(bcg[n]==n)return n;
    else return bcj(bcg[n]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    long long da=0;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) bcg[i]=i;
    for(int i=0;i<m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
    for(int i=0;i<k;i++) {
        cin>>ca[i];
        int hio;
        cin>>hio;
        c[i].push_back(hio);
    }
    sort(a,a+m,cmp);
    int bs=0;
    for(int i=0;i<m&&bs!=n-1;i++){
        int ux=bcj(a[i].u),vx=bcj(a[i].v);
        if(ux!=vx){
            da+=a[i].w;
            bs++;
            bcg[vx]=bcg[ux];
        }
    }
    cout<<da;
    return 0;
}
