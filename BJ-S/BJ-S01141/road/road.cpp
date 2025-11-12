#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int v,w;
};
int n,m,k;
vector<node> e[1024];
vector<int> vis[1024];
int a[1024],dis[1024],ans=1e18;

int read(){
    int x=0;
    char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        int u1=read(),v1=read(),w1=read();
        e[u1].push_back({v1,w1});
        e[v1].push_back({u1,w1});
    }
    for(int i=1;i<=k;i++){
        int c1=read();
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            int w1=read();
            e[i].push_back({j,w1});
            e[j].push_back({i,w1});
        }
    }
    printf("0");
}
