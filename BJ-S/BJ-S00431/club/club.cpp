#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e5+5;
int a[MAXN][5],fir[MAXN],sec[MAXN],cnt[5],p[MAXN];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        memset(p,0,sizeof(p));
        memset(cnt,0,sizeof(cnt));
        memset(fir,0,sizeof(fir));
        memset(sec,0,sizeof(sec));
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        int ans=0,sum=0;
        for(int i=1;i<=n;i++){
            int maxx=-1,t=1;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>maxx){
                    maxx=a[i][j];
                    t=j;
                }
            }
            ans+=maxx;
            fir[i]=t;
            cnt[t]++;
            maxx=-1,t=1;
            for(int j=1;j<=3;j++){
                if(a[i][j]>maxx && j!=fir[i]){
                    maxx=a[i][j];
                    t=j;
                }
            }
            sec[i]=t;
            //cout<<fir[i]<<' '<<sec[i]<<'\n';
        }
        int tot=0,k=0;
        for(int i=1;i<=3;i++){
            if(cnt[i]>n/2){
                k=i;
            }
        }
        if(k!=0){
            for(int j=1;j<=n;j++){
                if(fir[j]==k){
                    p[++tot]=a[j][fir[j]]-a[j][sec[j]];
                }
            }
            sort(p+1,p+tot+1);
            for(int i=1;i<=cnt[k]-n/2;i++){
                sum+=p[i];
                //cout<<p[i]<<' ';
            }
        }
        cout<<ans-sum<<'\n';
    }

    return 0;
}
