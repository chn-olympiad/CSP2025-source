#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5;
int fa[maxn],cnt,n,m,k,c[maxn],a[15][maxn],rt[15];
struct node{
    int y;
    int tot;
};
vector <node> g[maxn];
struct str{
    int x,y,z;
};
vector <str> h;
bool cmp(str x,str y){
    return x.z<y.z;
}
int fd(int x){
    if(fa[x]==x) return x;
    fa[x]=fd(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    int gx=fd(x);
    int gy=fd(y);
    fa[gx]=gy;
}
int p,fc;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=0;i<=n;i++){
        fa[i]=i;
    }

    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        g[x].push_back({y,z});
        g[y].push_back({x,z});
        h.push_back({x,y,z});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0) fc=1;
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    if(fc==0){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]==0){
                    rt[i]=j;
                    break;
                }
            }
            for(int j=1;j<=n;j++){
                if(j==rt[i]) continue;
                h.push_back({j,rt[i],a[i][j]});
            }
        }
        sort(h.begin(),h.end(),cmp);
        //cout<<rt[1]<<endl;

        for(auto i:h){
            if(p==n-1) break;

            if(fd(i.x)!=fd(i.y)){
                cnt+=i.z;
                merge(i.x,i.y);
                p++;
            }
        }
        cout<<cnt;
        return 0;
    }
    //////////////////////
    else if(k==0){
        sort(h.begin(),h.end(),cmp);
        //for(auto i:h){
        //    cout<<i.x<<" "<<i.y<<" "<<i.z<<endl;
        //}
        //cout<<fd(1)<<endl;
        //cout<<"11111111"<<endl;
        for(auto i:h){
                if(p==n-1) break;
            if(fd(i.x)!=fd(i.y)){
                    //cout<<i.x<<" "<<i.y<<endl;
                cnt+=i.z;
                merge(i.x,i.y);
                p++;
            }
        }
        cout<<cnt;
        return 0;
    }

    return 0;
}
/*
5 7 1
1 2 1
1 3 9
1 5 8
2 3 1
3 5 3
3 4 2
4 5 9
0 10 10 0 10 1


*/
