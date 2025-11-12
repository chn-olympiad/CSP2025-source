#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+500,V=(1<<20)+5;
int n,k,a[N],tg[V],f[N],g[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(tg,-1,sizeof tg);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]^=a[i-1];
    f[0]=g[0]=0,tg[a[0]]=0;
    for(int i=1;i<=n;i++){
        if(tg[a[i]^k]==-1)f[i]=0;
        else f[i]=g[tg[a[i]^k]]+1;
        g[i]=max(g[i-1],f[i]);
        tg[a[i]]=i;
    }
    cout<<g[n]<<'\n';
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}