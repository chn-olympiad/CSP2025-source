#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long n,m,k,fa[N],x,y,sum[1023],c[15],pos,v[15],num[1024][11],tmp,ma,tot,vis[N],pos2,pos3,vis2[N];
struct ed{
    long long u,v,w,f,c;
}e[N];
bool cmp(ed a,ed b){
    return a.w<b.w;
}
int lbt(int x){
    return x&(-x);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
        for(long long i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w,e[i].c=e[i].f=0;
        pos=m+1;
        for(long long i=1;i<=k;i++){
            cin>>c[i];
            for(long long j=1;j<=n;j++){
                e[pos].u=n+i,e[pos].v=j,e[pos].f=i,e[pos].c=c[i];
                cin>>e[pos].w;
                pos++;
            }
        }

        for(int i=0;i<=pow(2,k)-1;i++){
        tmp=i;
        num[i][0]=0;
        while(tmp){
            num[i][11]+=c[(long long)log2(lbt(tmp))+1];
            num[i][0]+=1;
            num[i][(long long)log2(lbt(tmp))+1]=1;
            tmp-=lbt(tmp);
            }
        }
        pos--;
        ma=0x3f3f3f3f;
        sort(e+1,e+1+pos,cmp);
        for(long long i=1;i<=n+k;i++)fa[i]=i;
        for(long long i=1;i<=pos;i++){
            if(e[i].f)continue;
            x=fa[e[i].u],y=fa[e[i].v];
            if(x!=y){
                tot++;
                fa[e[i].v]=x;
                sum[0]+=e[i].w;
            }
            if(tot==n)break;
        }
        ma=min(ma,sum[0]);
        for(int j=1;j<=pow(2,k)-1;j++){
            pos2=0;
            for(long long i=1;i<=n;i++)vis[i]=0;
            for(long long i=1;i<=n+k;i++)fa[i]=i;
            for(long long i=1;i<=pos;i++){
                if(!num[j][e[i].f])continue;
                x=fa[e[i].u],y=fa[e[i].v];
                if(x!=y){
                        if(e[i].u<=n&&!vis[e[i].u])pos2++,vis[e[i].u]=1;
                if(e[i].v<=n&&!vis[e[i].v])pos2++,vis[e[i].v]=1;
                        cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<" "<<e[i].f<<endl;
                    fa[e[i].v]=x;
                    sum[j]+=e[i].w;
                }
                if(pos2==n){
                    ma=min(ma,sum[j]+num[j][11]);
                    break;
                }
            }
            cout<<endl;
        }
        cout<<ma<<endl;
    return 0;
}

