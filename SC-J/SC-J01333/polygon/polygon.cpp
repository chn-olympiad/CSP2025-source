#include<bits/stdc++.h>
using namespace std;
#define db(x...) fprintf(stderr,x)
using ll=long long;
const ll Q=998244353;
const int N=5005;
ll f[N][N],ans;
int a[N],n,mx;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n),mx=a[n];
    f[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=mx;++j){
            f[i][j]=f[i-1][j];
            if(j>=a[i]) f[i][j]+=f[i-1][j-a[i]],f[i][j]>=Q?f[i][j]-=Q:0;
            // db("f(%d,%d)=%lld\n",i,j,f[i][j]);
        }
        f[i][mx+1]=f[i-1][mx+1];
        // db("%d to %d\n",mx-a[i]+1,mx);
        for(int j=mx-a[i]+1;j<=mx+1;++j) f[i][mx+1]+=f[i-1][j];
        f[i][mx+1]%=Q;
        // db("f(%d,>%d)=%lld\n",i,mx,f[i][mx+1]);
    }
    for(int i=1;i<=n;++i){
        for(int j=a[i]+1;j<=mx+1;++j) ans+=f[i-1][j];
    }
    cout<<ans%Q<<"\n";
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//9:09