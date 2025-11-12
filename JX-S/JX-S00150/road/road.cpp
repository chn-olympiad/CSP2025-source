#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
    friend bool operator<(node l, node r){
        return l.z<r.z;
    }
}s[1000005],ss[1000005];
int c[15],a[15][10005],fa[10005],p[15];
int find(int x){
    if(x==fa[x])
        return x;
    return fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>s[i].x>>s[i].y>>s[i].z;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    sort(s+1,s+m+1);
    long long ans=0;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    int cnt=0;
    for(int i=1;i<=m;i++){
        int x=s[i].x,y=s[i].y,z=s[i].z;
        if(find(x)==find(y))
            continue;
        fa[find(x)]=find(y);
        ans+=z;
        ss[++cnt]=s[i];
    }
    for(int i=1;i<=cnt;i++)
        s[i]=ss[i];
    for(int S=0;S<(1<<k);S++){
        int tot=cnt;
        int dian=0;
        for(int i=1;i<=10;i++)
            if(S&(1<<i-1))
                p[++dian]=i;
        for(int i=1;i<=n;i++){
            int x=0,z=2e9;
            for(int j=1;j<=dian;j++){
                if(a[p[j]][i]<z){
                    z=a[p[j]][i];
                    x=p[j];
                }
            }
            if(x)
                ss[++tot].x=i,ss[tot].y=x+n,ss[tot].z=z;
        }
        long long tmp=0;
        for(int i=1;i<=n+k;i++)
            fa[i]=i;
        sort(ss+1,ss+tot+1);
        for(int i=1;i<=tot;i++){
            int x=ss[i].x,y=ss[i].y,z=ss[i].z;
            if(find(x)==find(y))
                continue;
            fa[find(x)]=find(y);
            tmp+=z;
        }
        for(int i=1;i<=dian;i++)
            tmp+=c[p[i]];
        for(int i=1;i<=cnt;i++)
            ss[i]=s[i];
        ans=min(ans,tmp);
    }
    cout<<ans;
    return 0;
}
