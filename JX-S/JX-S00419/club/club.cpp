#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,T,op;
map<ll,map<ll,map<ll,ll>>>f;
struct V{
    ll a,b,c;
}e[100005];
void dbfs(ll x,ll y,ll z){
    ll io=x+y+z;
    if(x+y+z==n&&x<=n/2&&y<=n/2&&z<=n/2){
        op=max(op,f[x][y][z]);
        return;
    }
    if(x<n/2){
        f[x+1][y][z]=max(f[x][y][z],max(f[x+1][y-1][z],f[x+1][y][z-1]))+e[io+1].a;
        dbfs(x+1,y,z);
        f[x+1][y][z]=0;
    }
    if(y<n/2){
        f[x][y+1][z]=max(f[x][y][z],max(f[x-1][y+1][z],f[x][y+1][z-1]))+e[io+1].b;
        dbfs(x,y+1,z);
        f[x][y+1][z]=0;
    }
    if(z<n/2){
        f[x][y][z+1]=max(f[x][y][z],max(f[x][y-1][z+1],f[x-1][y][z+1]))+e[io+1].c;
        dbfs(x,y,z+1);
        f[x][y][z+1]=0;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        op=0;
        for(int i=1;i<=n;i++){
            cin>>e[i].a>>e[i].b>>e[i].c;
        }
        dbfs(0,0,0);
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=n/2;j++){
                for(int k=1;k<=n/2;k++){
                    f[i][j][k]=0;
                }
            }
        }
        cout<<op<<endl;
    }
    return 0;
}
