#include<bits/stdc++.h>
#define int long long
using namespace std;

inline long long read(){
    long long n=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        n=(n<<3)+(n<<1)+(c^48);
        c=getchar();
    }
    return n*f;
}

struct uvw{
    int u,v,w;
    friend bool operator<(uvw g,uvw h){
        return g.w<h.w;
    }
};

int n,m,k,f[10015],ans,mn=1e18;
vector<uvw>r;
vector<uvw>ry;
int c[15];

int find(const int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}

void scsy(){
    for(int i=1,ni=n+k;i<=ni;++i) f[i]=i;
    int cnti=0;
    for(int i=0;i<ry.size();++i){
        auto [u,v,w]=ry[i];
        if(find(u)==find(v))continue;
        r.push_back(ry[i]);
        f[find(u)]=find(v);
        if((++cnti)>=n-1)break;
    }
    return;
}

void scs(const int ban){
    for(int i=1,ni=n+k;i<=ni;++i) f[i]=i;
    int sum=0,cnti=0;
    for(int i=0;i<k;++i){
        if(!((1<<i)&ban)){sum+=c[i+1];cnti--;}
    }
    for(int i=0;i<r.size();++i){
        auto [u,v,w]=r[i];
        if(find(u)==find(v))continue;
        if(u>n&&((1<<(u-n-1))&ban)) continue;
        if(v>n&&((1<<(v-n-1))&ban)) continue;
        sum+=w;
        f[find(u)]=find(v);
        if((++cnti)>=n-1)break;
    }
    mn=min(mn,sum);
    return;
}

signed main(){
    //freopen("road3.in","r",stdin);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;++i){
        ry.push_back({read(),read(),read()});
    }
    sort(ry.begin(),ry.end());
    scsy();
    for(int i=1;i<=k;++i){
        c[i]=read();
        for(int j=1;j<=n;++j){
            r.push_back({i+n,j,read()});
        }
    }
    sort(r.begin(),r.end());
    for(int i=0,ni=(1<<k);i<ni;++i){
        scs(i);
    }
    cout<<mn;
    return 0;
}
//10 10
//2 6 100 100
