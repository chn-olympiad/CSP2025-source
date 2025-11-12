// #define DEBG 1
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+35;
const ll inf=1e18;

namespace IO{
    #define MAXBUFFSIZE (1<<20)
    char buff[MAXBUFFSIZE],*head=buff,*tail=buff;
    inline char gc(){
        #ifdef DEBG
            return getchar();
        #endif
        if(head==tail) head=buff,tail=head+fread(buff,1,MAXBUFFSIZE,stdin);
        return (head==tail)?(EOF):*(head++);
    }
    inline ll read(){
        ll res=0,tf=1;
        char c=gc();
        while(c<'0'||c>'9') tf*=(c=='-')?(-1):(1),c=gc();
        while(c>='0'&&c<='9') res=(res<<1)+(res<<3)+(c^48),c=gc();
        return res*tf;
    }
}
using namespace IO;

int n;
struct Node{
    ll w[4];
    ll mxid;
}a[maxn];

void input(){
    n=read();
    for(int i=1;i<=n;++i){
        ll mx=-inf,mxid=-1;
        for(int j=1;j<=3;++j){
            a[i].w[j]=read();
            if(a[i].w[j]>mx){
                mx=a[i].w[j];
                mxid=j;
            }
        }
        a[i].mxid=mxid;
    }
}

ll ans;
int cnt[5];
vector<ll> downv;
void solve(){
    for(int i=1;i<=n;++i){
        cnt[a[i].mxid]++;
        ans+=a[i].w[a[i].mxid];
    }
    int shownmax=0;
    for(int i=1;i<=3;++i){
        if(cnt[i]>cnt[shownmax]) shownmax=i;
    }
    if(cnt[shownmax]<=n/2){
        printf("%lld\n",ans);
        return;
    }
    downv.clear();
    for(int i=1;i<=n;++i){
        if(a[i].mxid==shownmax){
            ll mx=-inf;
            for(int j=1;j<=3;++j){
                if(j==shownmax) continue;
                mx=max(mx,a[i].w[j]);
            }
            downv.emplace_back(a[i].w[a[i].mxid]-mx);
        }
    }
    sort(downv.begin(),downv.end());
    for(int j=cnt[shownmax],k=0;j>n/2;--j,++k){
        ans-=downv[k];
    }
    printf("%lld\n",ans);
}

void reset(){
    cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
    ans=0;
}

int main(){
    #ifndef DEBG
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    #endif

    int T=read();
    while(T--){
        input();
        solve();
        reset();
    }   
    return 0;
}
