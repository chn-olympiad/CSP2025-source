#include<bits/stdc++.h>
#define pii pair<int,int>
#define vi vector<int>
#define vp vector<pii>
#define pb push_back
#define bs basic_string
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=2e5+5,maxm=5e6+5,bas=121313,mod=1e9+7;
int n,q;
string s1[maxn],s2[maxn],t1[maxn],t2[maxn];
int ans[maxn];
bs<ll>hs1[maxn],hs2[maxn],ht1[maxn],ht2[maxn];
ll pw[maxm];
bool gethsh(string&s,bs<ll>&b){
    b.pb(0);
    int cnt_b=0,fl=1;
    int m=s.size()-1;
    for(int i=1;i<=m;i++){
        ll hsh=b.back()*bas%mod+(s[i]-'a'+1);
        b.pb(hsh%mod);
        if(s[i]=='b'){
            cnt_b++;
        }
        else if(s[i]!='a'){
            fl=false;
        }
    }
    return fl&&cnt_b==1;
}
struct node{
    int x,y,z;
};
bool cmp(node x,node y){
    return x.x<y.x;
}
vector<node>a[maxn],qry[maxn];
vi tmp[maxn];
namespace sl2{
    // 性质B，欸，多少分来着……
    int d1[maxn<<2],d2[maxn<<2],ans[maxn];
    struct BIT{
        int b[maxn<<3],lim;
        void upd(int x,int p){
            for(;x<=lim;x+=x&-x){
                b[x]+=p;
            }
        }
        int qry(int x){
            int cur=0;
            for(;x>=1;x-=x&-x){
                cur+=b[x];
            }
            return cur;
        }
    }T;
    void slv(int pos){
        if(a[pos].empty()||qry[pos].empty()){
            return;
        }
        int t1=0,t2=0;
        for(auto v:a[pos]){
            d1[++t1]=v.x,d2[++t2]=v.y;
        }
        for(auto v:qry[pos]){
            d1[++t1]=v.x,d2[++t2]=v.y;
        }
        sort(d1+1,d1+t1+1);
        sort(d2+1,d2+t2+1);
        t1=unique(d1+1,d1+t1+1)-(d1+1);
        t2=unique(d2+1,d2+t2+1)-(d2+1);
        // cout<<pos<<":\n";
        for(auto&v:a[pos]){
            v.x=lower_bound(d1+1,d1+t1+1,v.x)-d1;
            v.y=lower_bound(d2+1,d2+t2+1,v.y)-d2;
            tmp[v.x].pb(v.y);
        };
        for(auto&v:qry[pos]){
            v.x=lower_bound(d1+1,d1+t1+1,v.x)-d1;
            v.y=lower_bound(d2+1,d2+t2+1,v.y)-d2;
        }
        sort(a[pos].begin(),a[pos].end(),cmp);
        sort(qry[pos].begin(),qry[pos].end(),cmp);

        // for(auto&v:a[pos]){
        //     cout<<v.x<<' '<<v.y<<'\n';
        // }
        // cout<<'\n';
        // for(auto&v:qry[pos]){
        //     cout<<v.x<<' '<<v.y<<'\n';
        // }
        // cout<<'\n';

        T.lim=t2;
        int cur=0;
        for(int i=1;i<=t1;i++){
            for(auto v:tmp[i]){
                T.upd(v,1);
            }
            while(cur<qry[pos].size()&&qry[pos][cur].x<i){
                cur++;
            }
            while(cur<qry[pos].size()&&qry[pos][cur].x==i){
                int to=qry[pos][cur].z;
                ans[to]=T.qry(qry[pos][cur].y);
                // cout << "query" << to << ' ' << T.qry(qry[pos][cur].y) << '\n';
                cur++;
            }
        }
        for(int i=1;i<=t1;i++){
            for(auto v:tmp[i]){
                T.upd(v,-1);
            }
            tmp[i].clear();
        }
    }
    int d[maxn<<1];
    void sl(){
        int mxlen=0,t=0;
        for(int i=1;i<=n;i++){
            int x=s1[i].find('b'),y=s2[i].find('b');
            d[++t]=y-x;
        }
        for(int i=1;i<=q;i++){
            int x=t1[i].find('b'),y=t2[i].find('b');
            d[++t]=y-x;
        }
        sort(d+1,d+t+1);
        t=unique(d+1,d+t+1)-(d+1);

        for(int i=1;i<=n;i++){
            int l=s1[i].size()-1,x=s1[i].find('b'),y=s2[i].find('b');
            int A=y-x,B=l-y,C=x;
            A=lower_bound(d+1,d+t+1,A)-d;
            a[A].pb((node){B,C,0});
        }
        for(int i=1;i<=q;i++){
            if(t1[i].size()!=t2[i].size()){
                continue;
            }
            int l=t1[i].size()-1,x=t1[i].find('b'),y=t2[i].find('b');
            int A=y-x,B=l-y,C=x;
            A=lower_bound(d+1,d+t+1,A)-d;
            qry[A].pb((node){B,C,i});
        }
        
        for(int i=1;i<=t;i++){
            slv(i);
        }
        for(int i=1;i<=q;i++){
            cout<<ans[i]<<'\n';
        }
    }
}
namespace sl1{
    // 暴力
    void pre(){
        pw[0]=1;
        for(int i=1;i<maxm;i++){
            pw[i]=pw[i-1]*bas%mod;
        }
    }
    ll hsh(bs<ll>bast,int l,int r){
        return ((bast[r]-bast[l-1]*pw[r-l+1]%mod+mod)%mod+mod)%mod;
    }
    void sl(){
        pre();
        for(int i=1;i<=q;i++){
            if(t1[i].size()!=t2[i].size()){
                cout<<0<<'\n';
                continue;
            }
            int ans=0;
            for(int j=1;j<=n;j++){
                int ssz=s1[j].size()-1;
                int tsz=t1[i].size()-1;
                for(int k=1;k<=tsz-ssz+1;k++){
                    int l=k+ssz-1;
                    // cout<<i<<' '<<j<<' '<<k<<' '<<l<<'\n';
                    // if(i*1000+j*100+k*10+l==1313){
                    //     cout<<hsh(ht1[i],1,k-1)<<' '<<hsh(ht2[i],1,k-1)<<'\n';
                    //     cout<<hsh(ht1[i],l+1,tsz)<<' '<<hsh(ht2[i],l+1,tsz)<<'\n';
                    //     cout<<hsh(ht1[i],k,l)<<' '<<hsh(hs1[j],1,ssz)<<'\n';
                    //     cout<<hsh(ht2[i],k,l)<<' '<<hsh(hs2[j],1,ssz)<<'\n';
                    // }
                    if(hsh(ht1[i],1,k-1)==hsh(ht2[i],1,k-1)
                     &&hsh(ht1[i],l+1,tsz)==hsh(ht2[i],l+1,tsz)
                     &&hsh(ht1[i],k,l)==hsh(hs1[j],1,ssz)
                     &&hsh(ht2[i],k,l)==hsh(hs2[j],1,ssz)){
                        
                        ans++;
                        break;
                    }
                    
                    // if(hsh(ht1[i],1,k-1)==hsh(ht2[i],1,k-1)
                    //  &&hsh(ht1[i],l+1,tsz)==hsh(ht2[i],l+1,tsz)){
                    //     ans++;
                    //     break;
                    // }

                }
            }
            cout<<ans<<'\n';
        }
    }
}
void Main(){
    cin>>n>>q;
    bool fl=1;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        s1[i]=' '+s1[i];
        s2[i]=' '+s2[i];
        fl&=gethsh(s1[i],hs1[i]);
        fl&=gethsh(s2[i],hs2[i]);
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
        t1[i]=' '+t1[i];
        t2[i]=' '+t2[i];
        fl&=gethsh(t1[i],ht1[i]);
        fl&=gethsh(t2[i],ht2[i]);
    }
    if(fl){
        sl2::sl();
    }
    else{
        sl1::sl();
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    Main();
}