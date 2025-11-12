#include<bits/stdc++.h>
using namespace std;
struct stu{
    long long u,v,w;
}a[1000010];
bool cmp(const stu &x,const stu &y){
    if(x.w!=y.w)return x.w<y.w;
    if(x.u!=y.u)return x.u<y.u;
    return x.v<y.v;
}
long long n,m,k,c,b[10010],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(long long i=1;i<=k;i++){
        cin>>c;
        for(long long j=1;j<=n;j++){
            cin>>b[j];
        }
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<n;i++){
        ans+=a[i].w;
    }
    cout<<ans;
    return 0;
}
