#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,N2=1e4+100;
long long n,m,k,b[20],f[N2],minn=1e14,c[20];
struct edge{
    long long u,v,w;
}a[N];//边
bool cmp(edge g,edge h){return g.w<h.w;}
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[i].u=x,a[i].v=y,a[i].w=z;
    }
    int cnt=m;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cnt++;
            int x;
            cin>>x;
            a[cnt].u=n+i,a[cnt].v=j,a[cnt].w=x;
        }
    }
    sort(a+1,a+1+cnt,cmp);
    for(int s=0;s<=((1<<k)-1);s++){
        long long ans=0,tmp=0;
        memset(b,0,sizeof(b));
        for(int i=1;i<=n+k;i++) f[i]=i;
        int t=s;
        while(t!=0){
            tmp++;
            if(t&1) {
                b[tmp]=1;
                ans+=c[tmp];
            }
            t=t>>1;
        }
        //知道那些点选了
        for(int i=1;i<=cnt;i++){
            if(find(a[i].u)==find(a[i].v)) continue;
            if(a[i].u-n>0){
                if(b[a[i].u-n]==0) continue;
                f[find(a[i].u)]=f[find(a[i].v)];
                ans+=a[i].w;
                continue;
            }
            f[find(a[i].u)]=f[find(a[i].v)];
            ans+=a[i].w;
        }
        minn=min(minn,ans);
    }
    cout<<minn<<endl;
    return 0;
}
//要开long long
