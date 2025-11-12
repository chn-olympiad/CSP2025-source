#include <bits/stdc++.h>
using namespace std;
#define ul unsigned long long
const int B=100;
vector<ul> has[400005];
ul pw[5000005];
void ip(){
    pw[0]=1;
    for(int i=1;i<=5000000;i++){
        pw[i]=pw[i-1]*B;
    }
}
void hsinit(string s,int p){
    has[p].clear();
    has[p].emplace_back(0);
    for(int i=1;i<=s.size();i++){
        has[p].emplace_back(has[p].back()*B+s[i-1]-'a'+1);
    }
    has[p].emplace_back(has[p].back()*B);
}
ul hs(int p,int l,int r){
    if(l<0||r>=has[p].size())return 27;
    if(r<l)return 0;
    return has[p][r]-has[p][l-1]*pw[r-l+1];
}
int l[200005],r[200005];
map<pair<ul,ul>,vector<int> > mp;
pair<pair<string,string>,pair<int,int> > diff(string a,string b){
    int R=0;
    for(int i=a.size()-1;i;i--){
        if(a[i]!=b[i]){
            R=i;
            break;
        }
    }
    int L;
    string aes="",bes="";
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            L=i;
            break;
        }
    }
    for(int i=L;i<=R;i++){
        aes=aes+a[i];
        bes=bes+b[i];
    }
    return make_pair(make_pair(aes,bes),make_pair(L+1,R+1));
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ip();
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s,t;
        cin>>s>>t;
        hsinit(s,i);
        hsinit(t,n+i);
        auto ans=diff(s,t);
        hsinit(ans.first.first,n*2+1);
        hsinit(ans.first.second,n*2+2);
        //cout<<"diff=("<<ans.first.first<<','<<ans.first.second<<")\n";
        //cout<<"mp["<<has[n*2+1].back()<<','<<has[n*2+2].back()<<"]<+-"<<i<<'\n';
        mp[make_pair(has[n*2+1].back(),has[n*2+2].back())].emplace_back(i);
        l[i]=ans.second.first;
        r[i]=ans.second.second;
        //cout<<"l="<<l[i]<<"\nr="<<r[i]<<'\n';
    }
    while(q--){
        string s,t;
        cin>>s>>t;
        if(s.size()!=t.size())continue;
        int ans=0;
        hsinit(s,n*2+1);
        hsinit(t,n*2+2);
        auto res=diff(s,t);
        hsinit(res.first.first,n*2+3);
        hsinit(res.first.second,n*2+4);
        //cout<<"diff=("<<res.first.first<<','<<res.first.second<<")\n";
        //cout<<"fd mp["<<has[n*2+3].back()<<','<<has[n*2+4].back()<<"]\n";
        vector<int> fd=mp[make_pair(has[n*2+3].back(),has[n*2+4].back())];
        int L=res.second.first,R=res.second.second;
        //cout<<"L="<<L<<'\n'<<"R="<<R<<'\n';
        //for(ul i:has[n*2+1])cout<<i<<' ';
        //cout<<'\n';
        for(int i:fd){
            //cout<<"i="<<i<<'\n';
            //cout<<"size="<<has[i].size()<<'\n';
            //cout<<"prev hash=["<<hs(i,1,l[i]-1)<<','<<hs(n*2+1,L-l[i]+1,L-1)<<"]["<<1<<','<<l[i]-1<<','<<L-l[i]+1<<','<<L-1<<"]\n";
            //cout<<"suff hash=["<<hs(i,r[i]+1,has[i].size()-1)<<','<<hs(n*2+1,R+1,R+has[i].size()-1-r[i])<<"]["<<r[i]+1<<','<<has[i].size()-1<<','<<R+1<<','<<R+has[i].size()-1-r[i]<<"]\n";
            if(l[i]==1||(hs(i,1,l[i]-1)==hs(n*2+1,L-l[i]+1,L-1))){
                if((r[i]=has[i].size()-2)||(hs(i,r[i]+1,has[i].size()-1)==hs(n*2+1,R+1,R+has[i].size()-1-r[i]))){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}