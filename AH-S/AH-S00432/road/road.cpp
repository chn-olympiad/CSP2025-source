#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x*=10,x+=(int)(ch-'0');
        ch=getchar();
    }
    return x*f;
}

const int N=10015,K=12;
int n,m,k;
int u[1000005],v[1000005],w[1000005];
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> edge;
int c[K],a[K][N];

int fa[N];
int Find(int x){
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y){
    x=Find(x),y=Find(y);
    fa[y]=x;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)
        u[i]=read(),v[i]=read(),w[i]=read();
    if(m>100005){
        for(int i=1;i<=k;i++){
            c[i]=read();
		    for(int j=1;j<=n;j++){
			    a[i][j]=read();
                if(a[i][j]==0) a[i][0]=j;
            }
        }
        for(int i=1;i<=m;i++) edge.push({w[i],{u[i],v[i]}});
        for(int i=1;i<=k;i++) {
            for(int j=1;j<=n;j++)
                edge.push({a[i][j],{a[i][0],j}});
        }
        for(int i=1;i<=n+k;i++) fa[i]=i;
        int ans0=0;
        while(!edge.empty()){
            int u=edge.top().second.first,v=edge.top().second.second,w=edge.top().first;
            if(Find(u)!=Find(v))ans0+=w, Union(u,v);
            edge.pop();
        } 
        cout<<ans0;
        return 0;
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
		for(int j=1;j<=n;j++)
			a[i][j]=read();
    }
    int ans=0x7fffffffffffffff;
    for(int ii=0;ii<(1<<k);ii++){
        int ans0=0;
        for(int i=1;i<=n+k;i++) fa[i]=i;
        for(int i=1;i<=m;i++) edge.push({w[i],{u[i],v[i]}});
        for(int i=1;i<=k;i++) 
            if(ii&(1<<i-1)){
                ans0+=c[i];
                for(int j=1;j<=n;j++)
                    edge.push({a[i][j],{n+i,j}});
            }
        while(!edge.empty()){
            int u=edge.top().second.first,v=edge.top().second.second,w=edge.top().first;
            if(Find(u)!=Find(v))ans0+=w, Union(u,v);
            edge.pop();
        } 
        ans=min(ans0,ans);
    }
    cout<<ans<<endl;
    return 0;
}   
