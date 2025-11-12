#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int c=0,x=1;
    char ch=getchar();

    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            x=-1;
        }
        ch=getchar();
    }

    while(ch>='0'&&ch<='9'){
        c=c*10+ch-'0';
        ch=getchar();
    }

    return c*x;
}

int n,m,k;
int c[15][10005];

int ans=1e18;

struct edge{
    int to,cost;
};

struct edge1{
    int from,to,cost;
};

bool operator<(const edge1 &b,const edge1 &a){
    return b.cost<a.cost;
}

vector<edge>p[10015];

int f(int u){
    bool c2[10015]={0};
    int ans1=0,t=1;
    c2[1]=1;
    while(t<u){
        priority_queue<edge1>q;
        for(int i=1;i<=u;i++){
            if(c2[i]){
                for(int j=0;j<p[i].size();j++){
                    edge now=p[i][j];
                    if(c2[now.to]==0){
                        q.push(edge1{i,now.to,now.cost});
                    }
                }
            }
        }
        edge1 now=q.top();
        ans1+=now.cost;
        c2[now.to]=1;
        t++;
    }
    return ans1;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cout<<1;

    n=read(),m=read(),k=read();

    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        p[u].push_back(edge{v,w});
        p[v].push_back(edge{u,w});
    }

    for(int i=1;i<=k;i++){
        c[i][0]=read();
        for(int j=1;j<=n;j++){
            c[i][j]=read();
        }
    }

    for(int i=0;i<(1<<k);i++){
        int ans1=0,i1=i,b=0;
        bool c1[15]={0};
        for(int cnt=1;cnt<=k;cnt++){
            c1[cnt]=i1%2;
            i1/=2;
        }
        for(int j=1;j<=k;j++){
            if(c1[j]){
                ans1+=c[j][0];
                b++;
                for(int t=1;t<=n;t++){
                    p[n+b].push_back(edge{t,c[j][t]});
                    p[t].push_back(edge{n+b,c[j][t]});
                }
            }
        }
        ans1+=f(n+b);
        for(int j=1;j<=k;j++){
            if(c1[j]){
                b++;
                p[n+b].clear();
            }
        }
        for(int j=1;j<=n;j++){
            for(int t=p[j].size()-1;t>=p[j].size()-b&&t>=0;t--){
                p[j][t].cost=1e18;
            }
        }
        ans=min(ans,ans1);
    }

    cout<<ans;

    return 0;
}
