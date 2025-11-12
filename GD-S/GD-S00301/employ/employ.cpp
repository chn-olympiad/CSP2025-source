#include<bits/stdc++.h>
#define ll long long
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fu(i,x,y) for(int i=(x);i<(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=20,M=(1<<18)+5,p=998244353;
int n,m,a[N],c[N],f[M][N],g[M][N],ans;
char str[N];
void add(int &x,int y){if((x+=y)>=p)x-=p;}
int main(){
    // freopen("employ2.in","r",stdin);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    fo(i,1,n)a[i]=str[i]-'0';
    fo(i,1,n)scanf("%d",&c[i]);
    if(m==n){
        int pd=0;
        fo(i,1,n)if(!a[i])pd=1;
        fo(i,1,n)if(!c[i])pd=1;
        if(pd)puts("0");
        else{
            ans=1;
            fo(i,1,n)ans=1ll*ans*i%p;
            printf("%d",ans);
        }
        return 0;
    }
    f[0][0]=1;
    int w=1<<n;
    fo(i,1,n){
        fu(j,0,w)fo(k,0,n)if(f[j][k]){
            int u=~j;
            while((u&-u)<w){
                int l=__builtin_ctz(u);
                if(c[l+1]>k&&a[i])add(g[j|1<<l][k],f[j][k]);
                else add(g[j|1<<l][k+1],f[j][k]);
                u-=u&-u;
            }
        }
        fu(j,0,w)fo(k,0,n)f[j][k]=g[j][k],g[j][k]=0;
    }
    fo(k,0,n)if(n-k>=m)add(ans,f[w-1][k]);
    printf("%d",ans);
}