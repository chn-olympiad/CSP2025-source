#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define co(x) cerr<<#x<<":"<<x<<"\n"
#define dbg cerr<<"--------\n"
#define endl '\n'
#define fi first
#define sc second
#define ls x<<1
#define rs (x<<1)|1
const int inf=3e18;
const int mod=1e9+7;
const int N=1e5+5;
int n,m,q,x,y,z,T,L,V,len,ans,now;
int a[N][3];
int id[N],cnt[3],b[N];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;m=-1;now=0;
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            id[i]=0;
            if(a[i][1]>a[i][id[i]]) id[i]=1;
            if(a[i][2]>a[i][id[i]]) id[i]=2;
            cnt[id[i]]++;
            ans+=a[i][id[i]];
        }
        for(int i=0;i<3;i++){
            if(cnt[i]>n/2){
                m=i;
            }
        }

        if(m<0) cout<<ans<<endl;
        else {
            for(int i=1;i<=n;i++){
                if(id[i]!=m) continue;
                b[++now]=inf;
                for(int j=0;j<3;j++){
                    if(j!=id[i]){
                        b[now]=min(b[now],a[i][id[i]]-a[i][j]);
                    }
                }
            }
            sort(b+1,b+1+now);
            for(int i=1;now>n/2;i++){
                now--;
                ans-=b[i];
            }
            cout<<ans<<endl;
        }
    }
   // cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
    return 0;
}
