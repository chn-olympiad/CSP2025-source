#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define INF 1e9
#define LLINF 1e18
#define ll long long
#define Mod 998244353
#define FILE1(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define FILE2(x) freopen(x".in","r",stdin),freopen(x".ans","w",stdout)
#define FILE3(x) freopen(x".in","r",stdin)
#define Mod 998244353
#define N 10400005
#define M 200005
using namespace std;
int read(){
    int x=0,f=1,ch=getchar();
    for(;!isdigit(ch);ch=getchar()) f=(ch=='-')?-1:1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
    return x*f;
}
int nn,q,s[N],sta[M],L[M],R[M],sum[N],cf[N];
int n,m='z',p,w,sa[N],rk[N],cnt[N],id[N],ork[N];
int lg[N],st[N][25],height[N],Len[M];
bool cmp(int x,int y,int w){return (ork[x]==ork[y] && ork[x+w]==ork[y+w]);}
void SA(){
    for(int i=1;i<=n;++i) ++cnt[rk[i]=s[i]];
    for(int i=1;i<=m;++i) cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;--i) sa[cnt[rk[i]]--]=i;
    for(w=1;;w<<=1,m=p){
        p=0;
        for(int i=n-w+1;i<=n;++i) id[++p]=i;
        for(int i=1;i<=n;++i) if(sa[i]>w) id[++p]=sa[i]-w;
        for(int i=1;i<=m;++i) cnt[i]=0;
        for(int i=1;i<=n;++i) ++cnt[rk[i]];
        for(int i=1;i<=m;++i) cnt[i]+=cnt[i-1];
        for(int i=n;i>=1;--i) sa[cnt[rk[id[i]]]--]=id[i];
        for(int i=1;i<=n;++i) ork[i]=rk[i];
        p=0;
        for(int i=1;i<=n;++i) rk[sa[i]]=cmp(sa[i],sa[i-1],w)?p:++p;
        if(p==n) break;
    }
    for(int i=1,k=0;i<=n;++i){
        if(k) --k;
        while(s[i+k]==s[sa[rk[i]-1]+k]) ++k;
        height[rk[i]]=k;
    }
    lg[0]=-1;
    for(int i=1;i<=n;++i) lg[i]=lg[i>>1]+1;
    for(int i=1;i<=n;++i) st[i][0]=height[i];
    for(int j=1;j<=lg[n];++j) for(int i=1;i+(1<<j)-1<=n;++i) st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
}
int LCP(int l,int r){
    if(l==r) return n-sa[l]+1;
    if(l>r) swap(l,r);
    ++l;int k=lg[r-l+1];
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
    FILE1("replace");
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin>>nn>>q;
    for(int i=1;i<=nn;++i){
        sta[i]=n+1;
        string t,tt;
        cin>>t>>tt;
        int l=t.length();
        for(int j=0;j<l;++j) s[++n]=t[j],s[++n]=tt[j];
        s[++n]=++m;
    }
    for(int i=1;i<=q;++i){
        string t,tt;
        cin>>t>>tt;
        if((int)t.length()!=(int)tt.length()) continue;
        sta[i+nn]=n+1;
        int l=t.length();Len[i]=l;
        for(int j=0;j<l;++j) s[++n]=t[j],s[++n]=tt[j];
        s[++n]=++m;
        while(t[L[i]]==tt[L[i]]) ++L[i];
        R[i]=l-1;
        while(t[R[i]]==tt[R[i]]) --R[i];
        ++L[i],++R[i];
    }
    SA();
    for(int i=1;i<=nn;++i) ++cf[rk[sta[i]]];
    for(int i=1;i<=n;++i) sum[i]=sum[i-1]+cf[i];
    for(int tt=1;tt<=q;++tt){
        if(!sta[tt+nn]){
            cout<<0<<'\n';
            continue;
        }
        ll ans=0;
        for(int i=sta[tt+nn];i<=sta[tt+nn]+L[tt]*2-1;i+=2){
            int x=(sta[tt+nn]+R[tt]*2-1)-i+1;
            int LL=rk[i],RR=rk[i]-1;
            {
                int l=1,r=rk[i]-1;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(LCP(rk[i],mid)>=x) LL=mid,r=mid-1;
                    else l=mid+1;
                }
            }
            {
                int l=rk[i],r=n;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(LCP(rk[i],mid)>=x) RR=mid,l=mid+1;
                    else r=mid-1;
                }
            }
            ans+=sum[RR]-sum[LL-1];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/