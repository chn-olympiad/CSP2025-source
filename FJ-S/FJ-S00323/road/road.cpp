#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

const int N = 2e6+5;
int n,m,k,fa[N],nm=0,c[15],a[15][N],cc[15],aa[15][N],kk,mn[15];
struct EDGE{int x,y;ll z;}edges[N];
vector<EDGE>ok,tmp,ttmp;
ll ans=0;

void init(){for(int i=1;i<=n+k;i++)fa[i]=i;}
int find(int x){return fa[x]=(fa[x]==x?x:find(fa[x]));}
void merge(int x,int y){fa[find(x)]=find(y);}
bool cmp(EDGE a,EDGE b){return a.z<b.z;}
void cmin(ll&x,ll y){if(x>y)x=y;}

int main(){
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    n=read(),m=read(),kk=read();for(int i=1;i<=m;i++){
        edges[i].x=read(),edges[i].y=read(),edges[i].z=read();
    }
    for(int t=1;t<=kk;t++){
        cc[t]=read();for(int j=1;j<=n;j++)aa[t][j]=read();
        if(cc[t]==0){
            int sb=0;
            for(int i=1;i<=n;i++)if(aa[t][i]==0){sb=i;break;}
            if(sb){
                for(int i=1;i<=n;i++)if(i!=sb){
                    edges[++m]=EDGE{sb,i,aa[t][i]};
                }
            }else{
                c[++k]=cc[t];
                for(int i=1;i<=n;i++)a[k][i]=aa[t][i];
            }
        }else{
            c[++k]=cc[t];
            for(int i=1;i<=n;i++)a[k][i]=aa[t][i];
        }
    }
    sort(edges+1,edges+1+m,cmp);init();
    for(int i=1;i<=m;i++)if(find(edges[i].x)!=find(edges[i].y)){
        merge(edges[i].x,edges[i].y);ok.emplace_back(edges[i]);
        ans+=edges[i].z;nm++;if(nm==n-1)break;
    }
    for(ll s=0;s<(1<<k);s++){tmp.clear();ll sum=0;
        for(int i=1;i<=k;i++)if((s>>(i-1))&1){
            for(int v=1;v<=n;v++)if(a[i][v]<=ok.back().z)tmp.emplace_back(EDGE{n+i,v,a[i][v]});
            sum+=c[i];
        }if(sum>ans)continue;if(tmp.empty())continue;
        ttmp.clear();sort(tmp.begin(),tmp.end(),cmp);
        int p=0,q=0;
        for(;p<ok.size()&&q<tmp.size();)if(ok[p].z<tmp[q].z){
            ttmp.emplace_back(ok[p]);p++;
        }else{
            ttmp.emplace_back(tmp[q]);q++;
        }
        for(;p<ok.size();p++)ttmp.emplace_back(ok[p]);
        for(;q<tmp.size();q++)ttmp.emplace_back(tmp[q]);
        init();nm=0;
        for(auto e:ttmp)if(find(e.x)!=find(e.y)){
            merge(e.x,e.y);sum+=e.z;nm++;
            if(nm==n+k-1)break;
        }cmin(ans,sum);
        // printf("s:%lld;sum:%lld\n",s,sum);
        // for(auto e:ttmp)printf("%d %d %d\n",e.x,e.y,e.z);
    }printf("%lld\n",ans);
    return 0;
}