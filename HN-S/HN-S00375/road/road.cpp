#include<bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) v.begin(),v.end()
#define lowbit(x) (x&-x)
using ull=unsigned long long;
using pii=pair<int,int>;
const int N=10000+15,inf=1e18;
int n,m,k,c[11];
int w[11][N];
struct line{
    int x,y,w;
}p[1000005];
inline int read(){
    register int x(0),t(0);
    static char ch=getchar();
    while(!isdigit(ch)){t|=(ch=='-');ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return t?-x:x;
}
int f[N];
vector<int> v;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),w=read();
        p[i]={x,y,w};
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++) w[i][j]=read();
    }
    iota(f+1,f+1+n,1);
    sort(p+1,p+1+m,[&](line A,line B){return A.w<B.w;});
    int res=0;
    for(int i=1;i<=m;i++){
        int x=find(p[i].x),y=find(p[i].y);
        if(x^y){
            res+=p[i].w;
            // cout<<"!!!!"<<p[i].x<<" "<<p[i].y<<" "<<p[i].w<<endl;
            v.emplace_back(i);
            f[x]=y;
        }
    }
    for(int S=0;S<(1<<k);S++){
        int tmp=0;
        for(int i=1;i<=k;i++)
            tmp+=(S>>i-1&1)*c[i];
        // cout<<"!!!!!!"<<S<<" "<<tmp<<endl;
        vector<line> l;
        for(int i:v) l.emplace_back(p[i]);
        for(int i=1;i<=k;i++)
            if(S>>i-1&1) for(int j=1;j<=n;j++) l.push_back((line){n+i,j,w[i][j]});
        iota(f+1,f+1+n+k,1);
        sort(All(l),[&](line A,line B){return A.w<B.w;});
        for(int i=0;i<l.size();i++){
            int x=l[i].x,y=l[i].y;
            if(find(x)^find(y)){
                // cout<<"!!!"<<x<<" "<<y<<" "<<l[i].w<<endl;
                tmp+=l[i].w;
                f[find(x)]=find(y);
            }
        }
        res=min(res,tmp);
    }
    cout<<res;
    return 0;
}