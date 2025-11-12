#include<bits/stdc++.h>
#define mod0 998244353
#define mod1 1000000009
#define L 5000005
#define N 200005
using namespace std;
namespace shan{
    typedef pair<int,int> pi2;
    typedef long long ll;
    const ll dt[2]={23919,51373};
    int tot_node;
    struct node{
        int son[27],siz,fail;
    }t[L];
    int root[N],tot;
    void insert(const string &x,int root){
        int len=x.length();
        for(int i=0;i<len;i++){
            if(!t[root].son[x[i]-'a'])
                t[root].son[x[i]-'a']=++tot_node;
            root=t[root].son[x[i]-'a'];
        }
        t[root].siz++;
    }
    void build(int rt){
        queue<int>q;
        for(int i=0;i<27;i++){
            int &to=t[rt].son[i];
            if(to){
                t[to].fail=rt;
                q.push(to);
            }else{
                to=rt;
            }
        }
        while(!q.empty()){
            int x=q.front();q.pop();
            t[x].siz+=t[t[x].fail].siz;
            for(int i=0;i<27;i++){
                int &to=t[x].son[i];
                if(to){
                    t[to].fail=t[t[x].fail].son[i];
                    q.push(to);
                }else{
                    to=t[t[x].fail].son[i];
                }
            }
        }
    }
    map<pi2,int>is;
    int n,q;
    int base[L][2];
    void __init__(){
        base[0][0]=base[0][1]=1;
        for(int i=1;i<=5e6;i++){
            base[i][0]=(ll)base[i-1][0]*dt[0]%mod0;
            base[i][1]=(ll)base[i-1][1]*dt[1]%mod1;
        }
    }
    pi2 fix(string &s,string &t){
        int len=s.length();
        int fir=0,lst=0;
        for(int i=0;i<len;i++){if(s[i]!=t[i]){fir=i;break;}}
        for(int i=len-1;i>=0;i--){if(s[i]!=t[i]){lst=i;break;}}
        int f0=0,f1=0;
        for(int i=0;i<=lst-fir;i++){
            f0=(f0+(ll)s[i+fir]*base[i][0])%mod0;
            f1=(f1+(ll)t[i+fir]*base[i][1])%mod1;
        }
        s="";
        for(int i=0;i<fir;i++)s+=t[i];
        s+='{';
        for(int i=lst+1;i<len;i++)s+=t[i];
        return {f0,f1};
    }
    signed main(){
        __init__();
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            string s,t;
            cin>>s>>t;
            if(s==t)continue;
            pi2 ret=fix(s,t);
            if(!is[ret]){
                is[ret]=++tot;
                root[tot]=++tot_node;
            }
            insert(s,root[is[ret]]);
        }
        for(int i=1;i<=tot;i++)build(root[i]);
        while(q--){
            string s,t;
            cin>>s>>t;
            pi2 ret=fix(s,t);
            if(is.find(ret)==is.end()){
                cout<<0<<'\n';
                continue;
            }
            int rt=root[is[ret]];
            int len=s.length();ll ans=0;
            for(int i=0;i<len;i++){
                rt=shan::t[rt].son[s[i]-'a'];
                ans+=shan::t[rt].siz;
            }
            cout<<ans<<'\n';
        }
        return 0;
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    shan::main();
    return 0;
}
/*
so fun
auto ac

*2400 ?
*/