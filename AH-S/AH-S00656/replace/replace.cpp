#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<class T>
void in(T &x){
    char c=getchar(); int f=1; x=0;
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    x*=f;
}
const int N=200010,L=5000010;
typedef pair<string,int> psi;
struct Type{
    string l,r;
    bool type;int id;
};
int n,q;
string sl,sr;
int ans[N];
struct Trie{
    int chi[L][26],cnt,tot[L];
    vector<psi > upd[L],qry[L];
    void init(){
        for(int i=1;i<=cnt;i++){
            memset(chi[i],0,sizeof(chi[i]));
            tot[i]=0;
            upd[i].clear(); qry[i].clear();
        }
        cnt=1;
    }
    void insert(const string &s,bool type,const string &s2,int id){
        int cur=1;
        for(int i=0;i<s.size();i++){
            if(!chi[cur][s[i]-'a'])
                chi[cur][s[i]-'a']=++cnt;
            cur=chi[cur][s[i]-'a'];
        }
        // cout<<s<<" "<<type<<" "<<s2<<" "<<id<<endl;
        if(type==0) upd[cur].push_back({s2,id});
        else qry[cur].push_back({s2,id});
    }
    void add(const string &s,int val){
        int cur=1;
        for(int i=0;i<s.size();i++){
            if(!chi[cur][s[i]-'a'])
                chi[cur][s[i]-'a']=++cnt;
            cur=chi[cur][s[i]-'a'];
        }
        // printf("%d %d\n",cur,val);
        tot[cur]+=val;
    }
    int query(const string &s){
        int ans=tot[1],cur=1;
        for(int i=0;i<s.size();i++){
            if(chi[cur][s[i]-'a']){
                cur=chi[cur][s[i]-'a'];
                ans+=tot[cur];
            }else return ans;
        }
        return ans;
    }
    void calc(int u){
        // cout<<u<<" "<<dep<<endl;
        for(const psi &x:upd[u])
            add(x.first,1);
        for(const psi &x:qry[u])
            ans[x.second]=query(x.first);//,printf("OK\n");
        for(int i=0;i<26;i++){
            if(chi[u][i])
                calc(chi[u][i]);
        }
        for(const psi &x:upd[u])
            add(x.first,-1);
    }
};
struct Worker{
    int chi[L][26],cnt=1;
    vector<Type> a[L];
    Trie trie;
    void insert(const string &s,const Type &data){
        int cur=1;
        for(int i=0;i<s.size();i++){
            if(!chi[cur][s[i]-'a'])
                chi[cur][s[i]-'a']=++cnt;
            // for(int i=0;i<26;i++) cerr<<chi[1][i]<<" "; cerr<<endl;
            cur=chi[cur][s[i]-'a'];
        }
        // if(s.size()>=10000) cout<<s.size()<<endl;
        // cout<<"Add data here "<<cur<<endl;
        a[cur].push_back(data);
    }
    void calc(int u){
        // cout<<"calcing "<<u<<' '<<dep<<endl;
        trie.init();
        for(const Type &d:a[u])
            trie.insert(d.l,d.type,d.r,d.id);//,cout<<"TRY"<<endl;
        trie.calc(1);
        // cout<<"go"<<endl;
        for(int i=0;i<26;i++){
            // printf("%d ",chi[u][i]);
            if(chi[u][i]){
                // cout<<u<<" going to "<<chi[u][i]<<endl;
                calc(chi[u][i]);
            }
        }
    }
}worker;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    // cout<<"here"<<endl;
    for(int i=1;i<=n;i++){
        cin>>sl>>sr;
        // cout<<sl<<' '<<sr<<endl;
        int len=sl.size();
        int l=-1,r=-1;
        for(int j=0;j<len;j++){
            if(sl[j]!=sr[j]){
                if(l==-1) l=j;
                r=j;
            }
        }
        if(l==-1) continue;
        // printf("%d %d\n",l,r);
        string sll="",srr="",s="";
        for(int i=l;i<=r;i++) s.push_back(sl[i]),s.push_back(sr[i]);
        for(int i=l-1;i>=0;i--) sll.push_back(sl[i]);
        for(int i=r+1;i<len;i++) srr.push_back(sl[i]);
        // cout<<s<<' '<<sl<<' '<<sr<<endl;
        // cout<<s<<endl;
        worker.insert(s,(Type){sll,srr,0,0});
        // cout<<i<<endl;
    }
    // cout<<"here"<<endl;
    for(int i=1;i<=q;i++){
        cin>>sl>>sr;
        if(sl.size()!=sr.size()) continue;
        int len=sl.size();
        int l=-1,r=-1;
        for(int j=0;j<len;j++){
            if(sl[j]!=sr[j]){
                if(l==-1) l=j;
                r=j;
            }
        }
        string sll="",srr="",s="";
        for(int i=l;i<=r;i++) s.push_back(sl[i]),s.push_back(sr[i]);
        for(int i=l-1;i>=0;i--) sll.push_back(sl[i]);
        for(int i=r+1;i<len;i++) srr.push_back(sl[i]);
        worker.insert(s,(Type){sll,srr,1,i});
    }
    // cout<<"here"<<endl;
    worker.calc(1);
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    return 0;
}
