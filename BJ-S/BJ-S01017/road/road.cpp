#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+5,M=1e4+5;
int n,m,k,cnt;
struct op{
    int x;
    int y;
    int c;
    bool operator <(const op a)const{
        return c<a.c;
    }
}f[N];
int p[N],fa[N];
int u[M][M];
int find(int x){
    if(fa[x]==x)return x;
    return x=fa[x];
}
void ust(int x,int y){
    fa[find(x)]=find(y);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)u[i][j]=INT_MAX;
    }
    for(int i=1;i<=m;i++){
        cnt++;
        int x,y,z;
        cin>>x>>y>>z;
        //cout<<x<<" "<<y<<" "<<z<<endl;
        if(x>y)swap(x,y);
        u[x][y]=min(u[x][y],z);
    }
    for(int i=1;i<=k;i++){
        int l;
        cin>>l;
        for(int i=1;i<=n;i++){
            cin>>p[i];
        }
        for(int x=1;x<=n;x++){
            for(int y=x+1;y<=n;y++){
                //cout<<x<<" "<<y<<" "<<p[x]+p[y]<<endl;
                u[x][y]=min(u[x][y],p[x]+p[y]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cnt++;
            f[cnt].x=i;
            f[cnt].y=j;
            f[cnt].c=u[i][j];
            //cout<<i<<" "<<j<<" "<<u[i][j]<<endl;
        }
    }
    sort(f+1,f+1+cnt);
    for(int i=1;i<=n;i++)fa[i]=i;
    int o=0,l=0;
    for(int i=1;i<=cnt;i++){
        if(l==n-1)break;
        if(find(f[i].x)!=find(f[i].y)){
            ust(f[i].x,f[i].y);
            o+=f[i].c;
            l++;
        }
    }
    cout<<o;
    return 0;
}
