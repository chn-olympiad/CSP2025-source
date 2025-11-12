#include<bits/stdc++.h>
#define int long long
#define base 13331
using namespace std;
int n,q,cnt;
map<pair<unsigned int,unsigned int>,int>pos;
signed sb[6000005][26];//~5e6*20 1e8 400mb
vector<unsigned int>v[6000005];//hash
vector<signed>qr[6000005];//ans
void ins(int p,string x,unsigned int y){
    for(int i=0;i<x.length();i++){
        if(!sb[p][x[i]-'a']){
            sb[p][x[i]-'a']=++cnt;
        }
        p=sb[p][x[i]-'a'];
    }
    v[p].push_back(y);
}
vector<unsigned int>yy[200005];
int ans[200005];
void inq(int p,string x,int y){
    for(int i=0;i<x.length();i++){
        if(!sb[p][x[i]-'a']){
            sb[p][x[i]-'a']=++cnt;
        }
        p=sb[p][x[i]-'a'];
    }
    qr[p].push_back(y);
}
unordered_map<unsigned int,int>m;
void dfs(int x){
    for(int i=0;i<v[x].size();i++)m[v[x][i]]++;
    for(int i=0;i<qr[x].size();i++){
        int p=qr[x][i];
        for(int j=0;j<yy[p].size();j++){
            ans[p]+=m[yy[p][j]];
        }
    }
    for(int i=0;i<26;i++){
        if(sb[x][i])dfs(sb[x][i]);
    }
    for(int i=0;i<v[x].size();i++)m[v[x][i]]--;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    vector<int>rt;
    while(n--){
        string x,y;cin>>x>>y;
        int l=-1,r=-1;
        for(int i=0;i<x.length();i++){
            if(x[i]!=y[i]){
                l=i;break;
            }
        }
        for(int i=x.length()-1;i>=0;i--){
            if(x[i]!=y[i]){
                r=i;break;
            }
        }
        if(l==-1)continue;
        unsigned int hx=0,hy=0;
        string ss;
        for(int i=r+1;i<x.length();i++)ss+=x[i];
        for(int i=l;i<=r;i++){
            hx=hx*base+x[i];
            hy=hy*base+y[i];
        }
        unsigned int hp=0;
        for(int i=0;i<l;i++){
            hp=hp*base+y[i];
        }
        pair<unsigned int,unsigned int>hh;hh.first=hx;hh.second=hy;
        if(!pos[hh]){
            pos[hh]=++cnt;
            rt.push_back(cnt);
        }
        ins(pos[hh],ss,hp);
    }
    for(int ii=1;ii<=q;ii++){
        string x,y;cin>>x>>y;
        if(x.length()!=y.length())continue;
        int l=-1,r=-1;
        for(int i=0;i<x.length();i++){
            if(x[i]!=y[i]){
                l=i;break;
            }
        }
        for(int i=x.length()-1;i>=0;i--){
            if(x[i]!=y[i]){
                r=i;break;
            }
        }
        if(l==-1)continue;
        unsigned int hx=0,hy=0;
        string ss;
        for(int i=r+1;i<x.length();i++)ss+=x[i];
        for(int i=l;i<=r;i++){
            hx=hx*base+x[i];
            hy=hy*base+y[i];
        }
        unsigned int hp=0,nw=1;
        yy[ii].push_back(0);
        for(int i=l-1;i>=0;i--){
            hp+=nw*x[i];
            nw*=base;
            yy[ii].push_back(hp);
        }
        pair<unsigned int,unsigned int>hh;hh.first=hx;hh.second=hy;
        if(!pos[hh])continue;
        inq(pos[hh],ss,ii);
    }
    for(int i=0;i<rt.size();i++){
        dfs(rt[i]);
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
    return 0;
}
