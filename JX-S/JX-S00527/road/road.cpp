#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e6+25;
int f[N];
int n,m,k;
int a[15][N];
inline int get(int x){return f[x]==x?x:f[x]=get(f[x]);}
struct EDGE{
    int x,y,z;
}e[N*2],e1[N*2];
inline bool cmp(EDGE a,EDGE b){return a.z<b.z;}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;int cnt=0;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        cin>>e[i].x>>e[i].y>>e[i].z;
    }
    cnt=m;
    for(int i=1;i<=k;i++)
        for(int j=0;j<=n;j++)
            cin>>a[i][j];
    int sum=0;
    for(int i=1;i<=k;i++)sum+=a[i][0];
    //cout<<sum<<'\n';
    if(!sum){
        for(int p=1;p<=k;p++){
            for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++){
                if(i!=j)e[++cnt].x=i,e[cnt].y=j,e[cnt].z=a[p][i]+a[p][j];
            }
        }
    }
    sort(e+1,e+1+cnt,cmp);
    int ans=0;
    for(int i=1;i<=cnt;i++){
        int X=get(e[i].x),Y=get(e[i].y);
        if(X!=Y){
            ans+=e[i].z;
            f[X]=Y;
        }
    }

    cout<<ans;
}
