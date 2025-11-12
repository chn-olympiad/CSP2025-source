#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+2;
int n,k;
int cnt[maxn];
bool a[maxn],vis[maxn],ax[maxn][22],x[maxn][22];  //a xu lie ; ax a er jin zhi ; x[j][i] ax[j][i] xor ax[j-1][i]
void t(int m,int j){
    while(m){
        ax[j][++cnt[j]]=m%2;
        m/=2;
    }
}
void xo(int j1,int j2){
    int l=max(cnt[j1],cnt[j2]);
    for(int i=1;i<=l;i++){
        if(ax[j2][i]==ax[j1][i]) x[j2][i]=0;
        else x[j2][i]=1;
    }
}
int unt(int j){
    int ans=0;
    for(int i=1,p=1;i<=cnt[j];i++,p*=2){
        int tmp=0;
        if(x[i]) tmp=1;
        ans+=tmp*p;
    }
    return ans;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int ans=0,cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t(a[i],i);
        xo(i-1,i);
        if(unt(i)==k){
            vis[i-1]=vis[i]=1;
            ans++;
            cnt+=2;
        }
    }
    if(n<=2){
        cout<<1;
        return 0;
    }
    int last=0;
    while(cnt<n){
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(!last) last=i;
                else{
                    xo(last,i);
                    if(unt(i)==k){
                        vis[last]=vis[i]=1;
                        last=0;
                        ans++;
                        cnt+=2;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
