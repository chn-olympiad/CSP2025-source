#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}
#define N 1009000
int fa[N];
struct fvv{
    int u;
    int v;
    int sum;
}f[N];
int c[12][N];
int n;
int nop;
#define il inline
#define ri register
il int find(int k){
    if(fa[k]==k)return k;
    return fa[k]=find(fa[k]);
}
il bool cmp(fvv a,fvv b){
    return a.sum<b.sum;
}
il int kru(int m){
    sort(f+1,f+m+1,cmp);
    int ans=0;
    int cnt=0;
    for(ri int i=1;i<=m;i++){
        int u=f[i].u,v=f[i].v;
        int af=find(u),bf=find(v);
        if(af==bf)continue;
        // cout<<f[i].sum<<'\n';
        fa[af]=bf;
        ans+=f[i].sum;
        cnt++;
        if(cnt==n-1)break;
    }
    return ans;
}
il void init(int x){
    for(ri int i=1;i<=x;i++){
        fa[i]=i;
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    int m=read(),k=read();
    for(ri int i=1;i<=m;i++){
        f[i].u=read();
        f[i].v=read();
        f[i].sum=read();
    }
    init(n);
    for(ri int i=1;i<=k;i++){
        for(ri int j=1;j<=n+1;j++){
            c[i][j]=read();
        }
    }
    nop=n;
    int ansmax=kru(m);
    if(k==0){
        cout<<ansmax;
        return 0;
    }
    int cnt=1;
    while(k>0){
        k--;
        int sum=c[cnt][1];
        if(sum>ansmax)continue;
        n++;
        for(ri int i=m+1;i<=m+1+nop;i++){
            f[i].u=n;
            f[i].v=i-m;
            f[i].sum=c[cnt][i-m+1];
        }
        init(n);
        m+=nop;
        cnt++;
        // if(clock()>9e5)cout<<111<<'\n';
    }
    ansmax=min(ansmax,kru(m));
    cout<<ansmax;
}