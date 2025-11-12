#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int u,v,w;
}r[10000005];
int a[10005];
int fd(int x){
    if(a[x]==x)return x;
    return a[x]=fd(a[x]);
}
void cn(int x,int y){
    a[fd(x)]=fd(y);
}
bool cmp(node xx,node yy){
    return xx.w<yy.w;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //cout<<double(sizeof(r))/1024/1024;
    int n,m,k,i;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++){
        cin>>r[i].u>>r[i].v>>r[i].w;
    }
    for(int z=0;z<k;z++){
        int l,qq;
        cin>>qq;
        int c[10005];
        for(int j=1;j<=n;j++){
            cin>>c[j];
            if(c[j]==0)l=j;
        }
        for(int j=1;j<=n;j++){
            r[i].u=l;
            r[i].v=j;
            r[i].w=c[j];
            i++;
        }
    }
    int sbctr=i-1;
    sort(r+1,r+sbctr+1,cmp);
    for(i=1;i<=sbctr;i++){
        a[i]=i;
    }
    int ans=0;
    for(i=1;i<=sbctr;i++){
        if(fd(r[i].u)!=fd(r[i].v)){
            cn(r[i].u,r[i].v);
            ans+=r[i].w;
        }
    }
    cout<<ans;
    return 0;
}
//
