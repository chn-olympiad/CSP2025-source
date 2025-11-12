#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
ull mod=(1ull<<61)-1;
ull pls(ull x,ull y){return (x+y>=mod?x+y-mod:x+y);}
ull sub(ull x,ull y){return (x<y?x+mod-y:x-y);}
ull mul(ull x,ull y){__uint128_t r=__uint128_t(x)*y;return pls(r>>61,r&mod);}
const int N=2e5,M=5e6,bse=1145;
int n,q;
char s0[M+5],s1[M+5];
unordered_map<ull,ll> umap;
vector<pair<ull,ull> > sl[M+5];
int mxl;
ull hq[M+5],pw[M+5];
ull cut(int l,int r){return sub(hq[r],mul(hq[l-1],pw[r-l+1]));}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=pw[0]=1;i<=M;i++)pw[i]=mul(pw[i-1],bse);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>(s0+1)>>(s1+1);int nn=strlen(s0+1);mxl=max(mxl,nn);
        ull hs=0,nhs;
        for(int j=1;j<=nn;j++){
            nhs=pls(mul(hs,bse),(s0[j]-'a'+1)*30+(s1[j]-'a'+1));
            sl[j].push_back(make_pair(hs,nhs));
            hs=nhs;
        }
        umap[hs]++;
    }
    for(int i=1;i<=mxl;i++){
        sort(sl[i].begin(),sl[i].end());
        sl[i].erase(unique(sl[i].begin(),sl[i].end()),sl[i].end());
        while(!sl[i].empty()){
            ull x=sl[i].back().first,y=sl[i].back().second;sl[i].pop_back();
            umap[y]+=umap[x];
        }
    }
    while(q--){
        ll ans=0;
        cin>>(s0+1)>>(s1+1);
        int ptl=0,nn=strlen(s0+1),ptr=nn+1;
        for(int i=1;i<=nn;i++)hq[i]=pls(mul(hq[i-1],bse),(s0[i]-'a'+1)*30+(s1[i]-'a'+1));
        while(ptl+1<=nn&&s0[ptl+1]==s1[ptl+1])ptl++;
        while(ptr-1>=0&&s0[ptr-1]==s1[ptr-1])ptr--;
        for(int i=1;i<=ptl+1;i++){
            if(!umap.count(cut(i,ptr-1)))continue;
            int l=ptr-1,r=nn;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(!umap.count(cut(i,mid)))r=mid-1;
                else l=mid;
            }
            ans+=umap[cut(i,l)];
            if(i<=ptr-2)ans-=umap[cut(i,ptr-2)];
        }
        cout<<ans<<'\n';
    }
}