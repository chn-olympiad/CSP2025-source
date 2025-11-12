#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int u,v,l;
}e[1000010],e1[10010],e2[120010];
int n,m,k,c[20],a[20][10010],f[10010],ans,cnt,all;
bool cmp(node x,node y){
    return x.l<y.l;
}
void start(int x){
    for(int i=1;i<=x;i++)f[i]=i;
}
void start2(){
    for(int i=1;i<n;i++)e2[i]=e1[i];
}
int find(int x){
    if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].l;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    sort(e+1,e+m+1,cmp);
    start(n);
    for(int i=1;i<=m;i++){
        if(find(e[i].u)==find(e[i].v))continue;
        f[find(e[i].u)]=find(e[i].v);
        ans+=e[i].l;
        cnt++;
        e1[cnt]=e[i];
        if(cnt==n-1)break;
    }
    for(int i=1;i<(1<<k);i++){
        int now=i,j=0,cc=0;
        int anss=0;
        start2();
        all=n-1;
        while(now){
            j++;
            if(now%2){
                cc++;
                anss+=c[j];
                for(int ss=1;ss<=n;ss++){
                    all++;
                    e2[all].u=cc+n;
                    e2[all].v=ss;
                    e2[all].l=a[j][ss];
                }
            }
            now/=2;
        }
        start(n+cc);
        sort(e2+1,e2+all+1,cmp);
        cnt=0;
        for(int ll=1;ll<=all;ll++){
            if(anss>=ans)break;
            if(find(e2[ll].u)==find(e2[ll].v))continue;
            f[find(e2[ll].u)]=find(e2[ll].v);
            anss+=e2[ll].l;
            cnt++;
            if(cnt==n+cc-1)break;
        }
        ans=min(ans,anss);
    }
    cout<<ans<<'\n';
    return 0;
}
