#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+5,maxm=1e6+5,maxk=10+5;
int read(){
    char c=getchar();
    int x=0;
    while(c<48){
        c=getchar();
    }
    while(c>47){
        x=x*10+c-48;
        c=getchar();
    }
    return x;
}
ll a[maxk][maxn],val[maxk];
struct node{
    int u,v;
    ll w;
}e[maxm],c[maxk][maxn],fin[maxn*maxk],tmp[maxn*maxk];
bool cmp(node x,node y){
    return x.w<y.w;
}
namespace DSU{
    int f[maxn*maxk];
    int fd(int a){
        return f[a]==a?a:f[a]=fd(f[a]);
    }
    bool lt(int a,int b){
        return fd(a)==fd(b);
    }
}
using DSU::fd;

int n,m,k;
void kru(){
    vector<int>ok;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++){
        DSU::f[i]=i;
    }
    int cur=0;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;
        if(fd(u)!=fd(v)){
            DSU::f[fd(u)]=fd(v);
            cur++;
            ok.push_back(i);
        }
        if(cur==n-1){
            break;
        }
    }
    cur=0;
    for(auto i:ok){
        e[++cur]=e[i];
    }
    m=n-1;
}
void mg(int n,node*x,int m,node*y,node*z){
    // printf("now merge : [%d, %d] and [%d, %d]. \n",x-fin+1,x-fin+n,y-fin+1,y-fin+m);
    int p1=0,p2=0;
    while(p1!=n||p2!=m){
        if(p1!=n&&p2!=m){
            if(x[p1+1].w<y[p2+1].w){
                z[p1+p2+1]=x[p1+1];
                p1++;
            }
            else{
                z[p1+p2+1]=y[p2+1];
                p2++;
            }
        }
        else if(p1!=n){
            z[p1+p2+1]=x[p1+1];
            p1++;
        }
        else{
            z[p1+p2+1]=y[p2+1];
            p2++;
        }
    }
}
int l[maxk],r[maxk];
void mysort(int L,int R){
    if(L==R){
        return;
    }
    int md=L+R>>1;
    mysort(L,md),mysort(md+1,R);
    mg(r[md]-l[L]+1,fin+l[L]-1,r[R]-l[md+1]+1,fin+l[md+1]-1,tmp);
    for(int i=l[L];i<=r[R];i++){
        fin[i]=tmp[i-l[L]+1];
    }
}
ll kru2(int siz){
    for(int i=1;i<=n+k;i++){
        DSU::f[i]=i;
    }
    int cur=0;
    ll allw=0;
    for(int i=1;;i++){
        int u=fin[i].u,v=fin[i].v;
        ll w=fin[i].w;
        if(fd(u)!=fd(v)){
            DSU::f[fd(u)]=fd(v);
            cur++;
            allw+=w;
        }
        if(cur==siz-1){
            break;
        }
    }
    // cout<<allw<<'\n';
    return allw;
}
void sl(){
    for(int i=1;i<=k;i++){
        sort(c[i]+1,c[i]+n+1,cmp);
    }
    ll ans=4e18;
    for(int st=0;st<(1<<k);st++){
        ll sum=0,pos=n-1,cnt=1;
        l[1]=1,r[1]=n-1;
        for(int i=1;i<n;i++){
            fin[i]=e[i];
        }
        for(int i=0;i<k;i++){
            if(st>>i&1){
                cnt++;
                l[cnt]=pos+1;
                sum+=val[i+1];
                for(int j=1;j<=n;j++){
                    fin[++pos]=c[i+1][j];
                }
                r[cnt]=pos;
            }
        }
        // for(int i=1;i<=pos;i++){
        //     cout<<fin[i].u<<' '<<fin[i].v<<' '<<fin[i].w<<'\n';
        // }
        // for(int i=1;i<=cnt;i++){
        //     cout<<l[i]<<' '<<r[i]<<'\n';
        // }
        // cout<<'\n';
        mysort(1,cnt);
        // for(int i=1;i<=pos;i++){
        //     cout<<fin[i].u<<' '<<fin[i].v<<' '<<fin[i].w<<'\n';
        // }
        // for(int i=1;i<=cnt;i++){
        //     cout<<l[i]<<' '<<r[i]<<'\n';
        // }
        // cout<<'\n';
        ans=min(ans,kru2(cnt-1+n)+sum);
        // cout<<"\n\n\n\n";
    }
    cout<<ans<<'\n';
}
void Main(){
    // cin>>n>>m>>k;
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        // cin>>e[i].u>>e[i].v>>e[i].w;
        e[i].u=read(),e[i].v=read(),e[i].w=read();
    }
    for(int i=1;i<=k;i++){
        // cin>>val[i];
        val[i]=read();
        for(int j=1;j<=n;j++){
            // cin>>a[i][j];
            a[i][j]=read();
            c[i][j].u=n+i,c[i][j].v=j,c[i][j].w=a[i][j];
        }
    }
    kru();
    // if(k==0){
        // ll ans=0;
        // for(int i=1;i<=n-1;i++){
        //     ans+=e[i].w;
        // }
        // cout<<ans<<'\n';
    // }
    // else{
        sl();
    // }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    Main();
}