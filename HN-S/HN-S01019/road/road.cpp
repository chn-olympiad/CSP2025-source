#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}

void file(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
}

const int N=1e4+50;
int n,m,k,f[N],a[N],bel[N],minn[12];
vector<pair<int,int>> p[N]; 
vector<int> q;
struct node{
    int x,y,w;
    bool operator<(const node &i)const{
        return w<i.w;
    }
}e[1000005],t[N*100];

inline int find(int x){
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}

signed main(){
    file();
    
    n=read(),m=read(),k=read(); 
    for(int i=1;i<=n+k;i++)
        f[i]=i;
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),w=read();
        p[x].push_back({y,w});
        p[y].push_back({x,w});
        e[i]={x,y,w};
    }
    if(k==0){
        sort(e+1,e+m+1);
        int now=0,ans=0;
        for(int i=1;i<=m;i++){
            int x=e[i].x,y=e[i].y,w=e[i].w;
            x=find(x),y=find(y);
            if(x==y) continue;
            f[x]=y,ans+=w;
            now++;
            if(now==n-1){
                cout<<ans<<"\n";
                break;
            }
        }
        return 0;
    }
    for(int i=1;i<=k;i++)
        minn[i]=1e18;
    int num=0;
    for(int i=1;i<=k;i++){
        a[i]=read();
        if(a[i]==0) num++;
        for(int j=1;j<=n;j++){
            int x=read();
            if(x) minn[i]=min(minn[i],x);
            if(!a[i] && x){
                j=find(j);
                f[j]=n+i;
            }
        }
    }
    return 0;
}