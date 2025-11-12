#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[20],ft[1100005],ct,uu,vv,zz,ans=1e18,as,n,m,k;
bool f[20];
struct nd{
    int u,v,z;
}aa[1100005];
inline bool cmp(nd a,nd b){
    return a.z<b.z;
}
inline int find(int dq){
    return ft[dq]==dq?dq:ft[dq]=find(ft[dq]);
}
inline int wk(){
    int ls=0;
    iota(ft+1,ft+1+n+k,1);
    for(int i=1;i<=m+n*k;i++){
        int u=aa[i].u,v=aa[i].v,z=aa[i].z;
        if((u>n&&!f[u-n])||(v>n&&!f[v-n])){
            continue;
        }
        u=find(u);
        v=find(v);
        if(u==v){
            continue;
        }
        ft[u]=v;
        ls=ls+z;
    }
    return ls;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> uu >> vv >> zz;
        aa[++ct]=nd{uu,vv,zz};
    }
    for(int i=1;i<=k;i++){
        cin >> c[i];
        for(int j=1;j<=n;j++){
            cin >> zz;
            aa[++ct]=nd{n+i,j,zz};
        }
    }
    sort(aa+1,aa+1+m+n*k,cmp);
    for(int i=0;i<(1<<k);i++){
        as=0;
        for(int j=1;j<=k;j++){
            f[j]=((i>>(j-1))&1);
            if(f[j]){
                as=as+c[j];
            }
        }
        as=as+wk();
        ans=min(ans,as);
    }
    cout << ans;
    return 0;
}
