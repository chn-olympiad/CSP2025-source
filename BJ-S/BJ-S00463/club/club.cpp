#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
template<typename T>
void chkmin(T &x,const T &y){x=min(x,y);}
template<typename T>
void chkmax(T &x,const T &y){x=max(x,y);}
const int MOD=998244353;
void add(int &x,int y){
    x+=y;
    if(x>=MOD) x-=MOD;
}
int qpow(int a,ll b){
    int mul=1;
    while(b){
        if(b&1) mul=(ll)mul*a%MOD;
        a=(ll)a*a%MOD;
        b>>=1;
    }
    return mul;
}
const int N=100005;
int n,a[N][3],id[N],cnt[3];
void solve(){
    scanf("%d",&n);
    for(int i=0;i<3;i++) cnt[i]=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        int mx=-1;
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]>mx) mx=a[i][j],id[i]=j;
        }
        cnt[id[i]]++;
        sum+=mx;
    }
    bool flag=true;
    for(int i=0;i<3;i++) flag&=(cnt[i]<=(n>>1));
    if(flag){
        printf("%d\n",sum);
        return;
    }
    int ans=0;
    for(int i=0;i<3;i++){
        sum=0;
        vector<int> vec;
        for(int j=1;j<=n;j++){
            sum+=a[j][i];
            int mx=-1;
            for(int k=0;k<3;k++) if(k!=i) chkmax(mx,a[j][k]);
            vec.push_back(mx-a[j][i]);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        for(int i=0;i<(n>>1);i++) sum+=vec[i];
        chkmax(ans,sum);
    }
    printf("%d\n",ans);
}
int main(){
    #ifndef JZQ
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    #endif
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}