#include<bits/stdc++.h>
#define il inline
#define reg register
#define rep(i,a,b) for(reg int (i)=(a);(i)<=(b);++(i))
#define drep(i,a,b) for(reg int (i)=(a);(i)>=(b);--(i))
#define pb push_back
#define ins insert
#define ull unsigned long long
using namespace std;
const int N=5e6+10,M=2e5+10;
ull base=1331,p[N];
struct hsh{
    ull a[N];
    ull get(int l,int r){
        // cerr<<l<<' '<<r<<'\n';
        if(l>r)return 0;
        return a[r]-a[l-1]*p[r-l+1];
    }
}lp,rp;

struct HS{
    int l,r;
    ull mids,tos,ls,rs;
}ori[M];
bool wtf[M];
pair<int,int> findif(string x,string y){
    int len=x.size();
    x=" "+x;y=" "+y;
    rep(i,1,len){
        lp.a[i]=lp.a[i-1]*base+(x[i]-'a'+1);
    }
    rep(i,1,len){
        rp.a[i]=rp.a[i-1]*base+(y[i]-'a'+1);
    }
    int lans,rans;
    rep(i,1,len){
        if(x[i]!=y[i]){
            lans=i;
            break;
        }
    }
    drep(i,len,1){
        if(x[i]!=y[i]){
            rans=i;
            break;
        }
    }
    return {lans,rans};
}
string reads1[M],reads2[M],readt1[M],readt2[M];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    p[0]=1;
    rep(i,1,5000000)p[i]=p[i-1]*base;
    int n,q;cin>>n>>q;
    bool flag=1;int cntb=0;
    rep(i,1,n){
        cin>>reads1[i]>>reads2[i];
        // cntb=0;for(char c:reads1[i])cntb+=(c=='b'),flag&=((c=='a')||c==('b'));flag&=(cntb==1);
        // cntb=0;for(char c:reads2[i])cntb+=(c=='b'),flag&=((c=='a')||c==('b'));flag&=(cntb==1);
    }
    rep(i,1,q){
        cin>>readt1[i]>>readt2[i];
        // cntb=0;for(char c:readt1[i])cntb+=(c=='b'),flag&=((c=='a')||c==('b'));flag&=(cntb==1);
        // cntb=0;for(char c:readt2[i])cntb+=(c=='b'),flag&=((c=='a')||c==('b'));flag&=(cntb==1);
    }
    // if(flag){

    // }
    rep(i,1,n){
        string s1=reads1[i],s2=reads2[i];
        if(s1==s2){
            wtf[i]=1;
            continue;
        }
        int len=s1.size();
        pair<int,int>gt=findif(s1,s2);
        int la=gt.first,ra=gt.second;
        int l=la-1,r=len-ra;
        ull ls=lp.get(1,la-1),rs=lp.get(ra+1,len);
        ull mids=lp.get(la,ra),tos=rp.get(la,ra);
        ori[i]=((HS){l,r,mids,tos,ls,rs});
    }
    rep(i,1,q){
        string s1=readt1[i],s2=readt2[i];
        int len=s1.size();
        pair<int,int>gt=findif(s1,s2);
        int la=gt.first,ra=gt.second;
        int l=la-1,r=len-ra;
        ull mids=lp.get(la,ra),tos=rp.get(la,ra);
        int ans=0;
        rep(j,1,n){
            if(wtf[j])continue;
            if(mids!=ori[j].mids)continue;
            if(tos!=ori[j].tos)continue;
            if(l<ori[j].l)continue;
            if(r<ori[j].r)continue;
            if(lp.get(la-ori[j].l,la-1)!=ori[j].ls)continue;
            if(lp.get(ra+1,ra+ori[j].r)!=ori[j].rs)continue;
            ++ans;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
