#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,w;
    bool operator <(const node &x) const{
        return x.w<w;
    }
};
priority_queue <node,vector<node>,less<node>> q;
int v[100005];
int f[10005][10005];
int pp[1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,x,y,w,ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        v[i]=1e9;
        for(int j=1;j<=n;j++)
            f[i][j]=1e9;
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y>>w;
        f[x][y]=f[y][x]=w;
    }
    int ppp;
    for(int i=1;i<=k;i++)
    {
        cin>>x;
        for(int j=1;j<=n;j++)
        {
            cin>>pp[j];
            if(pp[j]==0 ) ppp=j;
        }
        for(int j=1;j<=n;j++){
            if(ppp!=j) f[j][ppp]=f[ppp][j]=min(f[j][ppp],pp[j]);
        }
    }
    for(int i=2;i<=n;i++)
        if(f[1][i]!=1e9) q.push(node{1,i,f[1][i]});
    v[1]=0;
    for(int i=1;i<=n-1;i++){
        node p=q.top();
        q.pop();
        if(v[p.y]!=1e9||p.y==1) {i--;continue;}
        v[p.y]=p.w;
        ans+=p.w;
        for(int j=1;j<=n;j++)
            if(f[p.y][j]!=1e9) q.push(node{p.y,j,f[p.y][j]});
    }
    cout<<ans;
    return 0;
}
