#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
constexpr int N=2e5+5,M=5e6+5;
typedef long long ll;
int n,q;
string t[N][2],s[N][2];
int ls[N][2],lt[N][2];
map<string,vector<int>> mpn,mpq;
vector<int> samen,sameq;
ll ans[N];
namespace sub1{
    int trie[M][26],tot=0,fail[M],fa[M],cnt[M];
    inline void mian(){
        for(int i:samen){
            int u=0;
            rep(j,1,(int)s[i][0].size()-1){
                int &v=trie[u][s[i][0][j]-'a'];
                if(!v)v=++tot;
                fa[v]=u;
                u=v;
            }
            cnt[u]++;
        }
        queue<int> Q;
        rep(i,0,25)if(trie[0][i])Q.push(trie[0][i]);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            rep(i,0,25){
                int v=trie[u][i];
                if(v){
                    fail[v]=trie[fail[u]][i];
                    Q.push(v);
                }
                else trie[u][i]=trie[fail[u]][i];
            }
        }
        rep(i,0,tot)cnt[i]+=cnt[fa[i]];
        for(int i:sameq){
            int u=0;
            rep(j,1,(int)t[i][0].size()-1){
                u=trie[u][t[i][0][j]-'a'];
                ans[i]+=cnt[u];
            }
        }
    }
}
namespace sub2{
    inline void mian(string str){
        vector<int> vn=mpn[str];
        vector<int> vq=mpq[str];
        if(vn.size()>=98){
            // for(int i:vn)cout<<i<<" ";cout<<"!\n";
            // for(int i:vq)cout<<i<<" ";cout<<"!\n";
        }
        for(int i:vq){
            for(int j:vn){
                bool yes=1;
                rep(d,0,1){
                    int ln=ls[j][d],lq=lt[i][d];
                    if(ln>lq)yes=0;
                    else rep(k,0,ln-1)if(s[j][d][k]!=t[i][d][k])yes=0;
                }
                ans[i]+=yes;
            }
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    rep(i,1,n){
        string s1,s2;
        cin>>s1>>s2;
        int l=s1.size();
        int p=0,z=l-1;
        for(p=0;p<=l-1;p++)if(s1[p]!=s2[p])break;
        for(z=l-1;z>=0;z--)if(s1[z]!=s2[z])break;
        if(p<=z){
            string str=s1.substr(p,z-p+1)+s2.substr(p,z-p+1);
            mpn[str].pb(i);
            s[i][0]=s1.substr(0,p);
            s[i][1]=s1.substr(z+1,l-z-1);
            reverse(s[i][0].begin(),s[i][0].end());
            ls[i][0]=p;
            ls[i][1]=l-z-1;
            // if(i==101)cout<<str<<" "<<s[i][0]<<" "<<s[i][1]<<' '<<ls[i][0]<<' '<<ls[i][1]<<"\n";
        }
        else samen.pb(i),s[i][0]=s1;
    }
    rep(i,1,q){
        string s1,s2;
        cin>>s1>>s2;
        int l=s1.size();
        int p=0,z=l-1;
        for(p=0;p<=l-1;p++)if(s1[p]!=s2[p])break;
        for(z=l-1;z>=0;z--)if(s1[z]!=s2[z])break;
        if(p<=z){
            string str=s1.substr(p,z-p+1)+s2.substr(p,z-p+1);
            mpq[str].pb(i);
            t[i][0]=s1.substr(0,p);
            t[i][1]=s1.substr(z+1,l-z-1);
            reverse(t[i][0].begin(),t[i][0].end());
            lt[i][0]=p;
            lt[i][1]=l-z-1;
            // if(i==101)cout<<str<<" "<<t[i][0]<<" "<<t[i][1]<<' '<<lt[i][0]<<' '<<lt[i][1]<<"\n";
        }
        else sameq.pb(i),t[i][0]=s1;
    }
    // for(auto it=mpn.begin();it!=mpn.end();it++)if(it->second.size()>=98)cout<<it->second.size()<<"\n";
    sub1::mian();
    for(auto it=mpq.begin();it!=mpq.end();it++){
        string str=it->first;
        if(mpn[str].size()==0)continue;
        // if(mpn[str].size()==360)cout<<str<<"\n";
        sub2::mian(str);
    }
    rep(i,1,q)cout<<ans[i]<<"\n";
    return 0;
}