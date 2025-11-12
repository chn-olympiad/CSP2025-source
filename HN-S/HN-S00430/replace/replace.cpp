#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
int n,q;
int trie1[5000010][26],trie2[5000010][26];
int zm1[5000010],zm2[5000010];
int fail1[5000010],fail2[5000010];
int fa1[5000010],fa2[5000010];
int d1[5000010],d2[5000010];
vector<int>v1[5000010],v2[5000010];
vector<int>sum1[5000010],sum2[5000010];
int in[5000010],out[5000010],ttott,nfd[5000010];
int len1[500010],len2[500010];
int ans[5000010];
int an[5000010];
int que[5000010],tp,tl;
int cnt1,cnt2;
string s,t;
void dfs2(int sx,int f){
    in[sx]=++ttott;
    for(auto y:v2[sx]){
        dfs2(y,sx);
    }
    out[sx]=ttott;
}
struct aaaa{
    int sx,wz;
};
vector<aaaa>qq[5000010];
int tt[500010];
void add(int l,int r,int d){
    for(int x=l;x<=r;x++)tt[x]+=d;
}
int query(int sx){
    return tt[sx];
}
void gtans(int sx){
    for(auto y:sum1[sx]){
        //cout<<sx<<' '<<y<<' '<<an[y]<<' '<<in[an[y]]<<' '<<out[an[y]]<<'\n';
        add(in[an[y]],out[an[y]],1);
    }
    for(auto y:qq[sx]){
        //cout<<sx<<' '<<y.sx<<' '<<y.wz<<' '<<nfd[y.wz]<<'\n';
        //for(int x=1;x<=cnt2;x++)cout<<tt[x]<<' ';
        //cout<<'\n';
        ans[y.sx]+=query(in[y.wz]);
    }
    for(auto y:v1[sx]){
        gtans(y);
    }
    for(auto y:sum1[sx]){
        add(in[an[y]],out[an[y]],-1);
    }
}*/
int n,q;
string s,t;
int hsh1[200010],hsh2[200010],len[2000010];
int h1[5000010],h2[5000010];
const int bse=13331;
const int mod=1e9+7;
int qp[5000010];
int gt1(int l,int r){
    return (h1[r]-h1[l-1]*qp[r-l+1]%mod+mod)%mod;
}
int gt2(int l,int r){
    return (h2[r]-h2[l-1]*qp[r-l+1]%mod+mod)%mod;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    qp[0]=1;
    for(int x=1;x<=5000000;x++)qp[x]=qp[x-1]*bse%mod;
    for(int x=1;x<=n;x++){
        cin>>s>>t;
        int m=s.size();
        len[x]=m;
        for(int y=0;y<m;y++){
            hsh1[x]=hsh1[x]*bse%mod+(s[y]-'a'+1);
            hsh2[x]=hsh2[x]*bse%mod+(t[y]-'a'+1);
            hsh1[x]%=mod;
            hsh2[x]%=mod;
        }
    }
    while(q--){
        cin>>s>>t;
        if(s.size()!=t.size()){
            cout<<0<<'\n';
            continue;
        }
        int m=s.size();
        s=" "+s,t=" "+t;
        int l=n+1,r=-1;
        for(int x=1;x<=m;x++){
            h1[x]=h1[x-1]*bse%mod+(s[x]-'a'+1);
            h2[x]=h2[x-1]*bse%mod+(t[x]-'a'+1);
            h1[x]%=mod;
            h2[x]%=mod;
            if(s[x]!=t[x]){
                l=min(l,x);
                r=max(r,x);
            }
        }
        int ans=0;
        for(int x=1;x<=n;x++){
            for(int y=1;y+len[x]-1<=m;y++){
                if(y<=l&&y+len[x]-1>=r){
                    if(gt1(y,y+len[x]-1)==hsh1[x]&&gt2(y,y+len[x]-1)==hsh2[x]){
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    /*
    cin>>n>>q;
    for(int x=1;x<=n;x++){
        cin>>s>>t;
        int m=s.size();
        s=" "+s,t=" "+t;
        int nw=0;
        for(int y=1;y<=m;y++){
            int gq=s[y]-'a';
            if(trie1[nw][gq]==0){
                trie1[nw][gq]=++cnt1;
                fa1[cnt1]=nw;
                zm1[cnt1]=gq;
                len1[cnt1]=len1[fa1[nw]]+1;
            }
            nw=trie1[nw][gq];
        }
        sum1[nw].push_back(x);
        nw=0;
        for(int y=1;y<=m;y++){
            int gq=t[y]-'a';
            if(trie2[nw][gq]==0){
                trie2[nw][gq]=++cnt2;
                fa2[cnt2]=nw;
                zm2[cnt2]=gq;
                len2[cnt2]=len2[fa2[nw]]+1;
            }
            nw=trie2[nw][gq];
        }
        an[x]=nw;
        sum2[nw].push_back(x);
    }
    tp=tl=1;
    que[1]=0;
    while(tp>=tl){
        int sx=que[tl];tl++;
        int nw=fa1[sx];
        int gq=zm1[sx];
        if(nw){
            nw=fail1[nw];
            while(nw&&trie1[nw][gq]==0)nw=fail1[nw];
            fail1[sx]=trie1[nw][gq];
        }
        if(sx)v1[fail1[sx]].push_back(sx);
        for(int y=0;y<26;y++){
            if(trie1[sx][y]!=0)que[++tp]=trie1[sx][y];
        }
    }
    tp=tl=1;
    que[1]=0;
    while(tp>=tl){
        int sx=que[tl];tl++;
        int nw=fa2[sx];
        int gq=zm2[sx];
        if(nw){
            nw=fail2[nw];
            while(nw&&trie2[nw][gq]==0)nw=fail2[nw];
            fail2[sx]=trie2[nw][gq];
        }
        if(sx)v2[fail2[sx]].push_back(sx);
        for(int y=0;y<26;y++){
            if(trie2[sx][y]!=0)que[++tp]=trie2[sx][y];
        }
    }
    for(auto y:v2[0]){
        dfs2(y,0);
    }
    for(int _=1;_<=q;_++){
        cin>>s>>t;
        int m=s.size();
        s=" "+s,t=" "+t;
        if(s.size()!=t.size()){
            continue;
        }
        int l=m+1,r=-1;
        for(int x=1;x<=m;x++){
            if(s[x]!=t[x]){
                l=min(l,x);r=max(r,x);
            }
        }
        int nw1=0,nw2=0;
        for(int x=1;x<=m;x++){
            int gq=s[x]-'a';
            while(nw1&&trie1[nw1][gq]==0){
                nw1=fail1[nw1];
            }
            nw1=trie1[nw1][gq];
            gq=t[x]-'a';
            while(nw2&&trie2[nw2][gq]==0){
                nw2=fail2[nw2];
            }
            nw2=trie2[nw2][gq];
            if(x-len1[nw1]+1>l||x-len2[nw2]+1>l)break;
            if(x>=r){
                qq[nw1].push_back({_,nw2});
            }
            //cout<<_<<' '<<nw1<<' '<<nw2<<'\n';
            //cout<<x<<' '<<nw1<<' '<<nw2<<' '<<sum1[nw1]<<' '<<sum2[nw2]<<' '<<ans<<'\n';
        }
    }
    gtans(0);
    for(int x=1;x<=q;x++){
        cout<<ans[x]<<'\n';
    }
    return 0;*/
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