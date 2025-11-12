#include<bits/stdc++.h>
using namespace std;

long long p[10010][10010],cmp[10010];

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    long long n,m,k;
    long long ans=0;
    cin>>n>>m>>k;
    for(long long i=0;i<=n+1;i++) for(long long j=0;j<=n+1;j++) p[i][j]=-1;
    for(long long j=0;j<=n+1;j++) cmp[j]=-1;
    long long x,y,z;
    for(long long i=0;i<m;i++){
        cin>>x>>y>>z;
        if(p[x][y]==-1){
            p[x][y]=z;
            p[y][x]=z;
        }
        else{
            if(p[x][y]>z){
                p[x][y]=z;
                p[y][x]=z;
            }
        }
    }
    for(long long i=1;i<=n;i++){
            long long z=1e9+1;
            for(long long j=1;j<=n;j++) if(p[j][i]!=-1) z=min(z,p[j][i]);
            if(z==1e9+1) z=-1;
            cmp[i]=z;
    }
    for(long long i=1;i<=n;i++){
            if(cmp[i]==-1){
                ans=-1;
                break;
            }
            ans+=cmp[i];
    }
    while(k--){
        long long a,b;
        cin>>a;
        for(long long i=1;i<=n;i++){
            cin>>b;
            if(cmp[i]==-1) a+=b;
            else if(cmp[i]>b) a+=b;
            else a+=cmp[i];
        }
        if(ans==-1) ans=a;
        else ans=min(a,ans);
    }
    cout<<ans;
    return 0;
}
