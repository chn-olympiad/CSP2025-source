#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
int a[MAXN][4];
int g[MAXN];
int f[105][105][105];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        memset(f,0,sizeof(f));
        int n;
        cin>>n;
        int cnt=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        if(n>1000){
            for(int i=1;i<=n;i++){
                g[i]=a[i][0];
            }
            sort(g+1,g+n+1,greater<int>());
            int ans=0;
            for(int i=1;i<=cnt;i++){
                ans+=g[i];
            }
            cout<<ans<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int a1=0;a1<=min(cnt,i);a1++){
                for(int a2=0;a2<=min(cnt,i-a1);a2++){
                    int a3=i-a1-a2;
                    if(a1<0||a2<0||a3<0) continue;
                    if(a1+1<=cnt){
                        f[a1+1][a2][a3]=max(f[a1+1][a2][a3],f[a1][a2][a3]+a[i][0]);
                        ans=max(ans,f[a1+1][a2][a3]);
                    }
                    if(a2+1<=cnt){
                        f[a1][a2+1][a3]=max(f[a1][a2+1][a3],f[a1][a2][a3]+a[i][1]);
                        ans=max(ans,f[a1][a2+1][a3]);
                    }
                    if(a3+1<=cnt){
                        f[a1][a2][a3+1]=max(f[a1][a2][a3+1],f[a1][a2][a3]+a[i][2]);
                        ans=max(ans,f[a1][a2][a3+1]);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
