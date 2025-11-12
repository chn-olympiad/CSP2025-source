#include <bits/stdc++.h>
using namespace std;
int n,m,k,fa[1000005],c[15][10005];
map<pair<int,int>,int> mp;
struct A{
    long long x,y,z;
}a[1000005];
bool cmp(A t1,A t2){
    return t1.z<t2.z;
}
int fi(int x){
    if(x==fa[x])return x;
    return fa[x]=fi(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    int o=m;
    for(int i=1;i<=k;i++){
        int y;
        cin>>y;
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
        for(int j=1;j<=n;j++){
            for(int j1=1;j1<=n;j1++){
                if(j!=j1&&c[i][j]==0&&c[i][j1]==0&&mp[{j,j1}]==0){
                    mp[{j,j1}]=1;
                    a[++o].x=j;
                    a[o].y=j1;
                    a[o].z=0;
                }
            }
        }
    }
    long long ans=0;
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        int fx=fi(a[i].x),fy=fi(a[i].y);
        if(fx!=fy){
            mp[{a[i].x,a[i].y}]=a[i].z;
            ans+=a[i].z;
            fa[fx]=fy;
        }
    }
    cout<<ans<<endl;
    return 0;
}
