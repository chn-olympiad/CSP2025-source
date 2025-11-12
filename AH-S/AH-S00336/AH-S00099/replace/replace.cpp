/*

       2025.11.1

 * Happy Zenith Noises *

*/
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int>P;
typedef pair<ull,ull>PP;
const int MAXN=200005,MAXN2=5000005,inf=0x3f3f3f3f;
const ull mul=233;
int n,q,ans[MAXN];
ull ta[MAXN2],tb[MAXN2],mu[MAXN2];
bool vis[MAXN];
map<ull,int>ts,mp2;int cnt2;
map<int,int>_rev;
map<PP,int>mp;int cnt;
vector<int>ask[MAXN],g[MAXN],ggg[MAXN];
vector<ull>gg[MAXN],pre[MAXN],suf[MAXN];
struct node{
    ull l,mid,r;
}aa[MAXN];
ull gt(int l,int r){
    return ta[r]-ta[l-1]*mu[r-l+1];
}
ull gtb(int l,int r){
    return tb[r]-tb[l-1]*mu[r-l+1];
}
int rev(ull x,ull y){
    if(mp.find({x,y})==mp.end())mp[{x,y}]=++cnt;
    return mp[{x,y}];
}
int rev2(ull x){
    if(mp2.find(x)==mp2.end())mp2[x]=++cnt2;
    return mp2[x];
}
void cle(int x){vector<int>ffs;swap(ggg[x],ffs);}
void dfs(int x,const vector<int> &f){
    if(f.size()==0)return ;
    if(pre[f[0]][x]<MAXN)for(ull i:gg[pre[f[0]][x]])ts[i]++;
    //cout<<"\n";
    for(int i:f){
        if(pre[i].size()==x+1){
            vis[i]=1;//cout<<"&"<<x<<' '<<i<<'\n';
            for(ull j:suf[i]){
                //cout<<"FS!";
                if(ts.find(j)!=ts.end())ans[i]+=ts[j];
            }
            //cout<<"\n";
        }
    }
    _rev.clear();int tot=0;vector<vector<int> >ggg;
    for(int i:f){
        if(vis[i])continue;
        if(_rev.find(pre[i][x+1])==_rev.end()){
            _rev[pre[i][x+1]]=tot++;
            ggg.pb(vector<int>() );
        }
        ggg[_rev[pre[i][x+1]]].pb(i);
    }
    for(int i=0;i<tot;i++)dfs(x+1,ggg[i]);
    if(pre[f[0]][x]<MAXN)for(ull i:gg[pre[f[0]][x]])ts[i]--;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    mu[0]=1;
    for(int i=1;i<MAXN2;i++)mu[i]=mu[i-1]*mul;
    for(int i=1;i<=n;i++){
        string a,b;cin>>a>>b;
        if(a==b)continue;
        int mx=0,mn=inf;
        for(int j=0;j<a.size();j++)ta[j+1]=ta[j]*mul+(ull)(a[j]-'a'+1),tb[j+1]=tb[j]*mul+(ull)(b[j]-'a'+1);
        for(int j=0;j<a.size();j++)if(a[j]!=b[j])mx=max(mx,j+1),mn=min(mn,j+1);
        aa[i]=node{gt(1,mn-1),gt(mn,mx),gt(mx+1,a.size())};
        g[rev(gt(mn,mx),gtb(mn,mx))].pb(i);
    }
    for(int i=1;i<=q;i++){
        string a,b;cin>>a>>b;
        if(a.size()!=b.size())continue;
        int mx=0,mn=inf;
        for(int j=0;j<a.size();j++)ta[j+1]=ta[j]*mul+(a[j]-'a'+1),tb[j+1]=tb[j]*mul+(b[j]-'a'+1);
        for(int j=0;j<a.size();j++)if(a[j]!=b[j])mx=max(mx,j+1),mn=min(mn,j+1);
        if(mp.find({gt(mn,mx),gtb(mn,mx)})==mp.end())continue;
        suf[i].pb(0);
        for(int j=mx+1;j<=a.size();j++)suf[i].pb(gt(mx+1,j));
        pre[i].pb(0);
        for(int j=mn-1;j>=1;j--)pre[i].pb(gt(j,mn-1));
        ask[mp[{gt(mn,mx),gtb(mn,mx)}]].pb(i);
    }
    for(int i=1;i<=cnt;i++){
        //cout<<"_____________________\n";
        if(g[i].size()==0||ask[i].size()==0)continue;
        for(int j=1;j<=cnt2;j++)gg[j].clear();
        cnt2=0;mp2.clear();ts.clear();

        for(int j:g[i]){
                //cout<<"*";
            gg[rev2(aa[j].l)].pb(aa[j].r);
        }
        for(int j:ask[i]){
            for(int k=0;k<pre[j].size();k++)pre[j][k]=rev2(pre[j][k]);
        }
        //cout<<"!!!\n";
        //for(int j:ask[i])cout<<j<<' ';
        //cout<<'\n';
        dfs(0,ask[i]);
    }int ccnt=0;
    for(int i=1;i<=q;i++){
            if(ans[i]<0)ccnt++;
            cout<<ans[i]<<'\n';
    }
    //cout<<"?"<<ccnt;
    return 0;
}
/*
2 1
a b
aa bb
aa bb
*/
