// T3 [60,100]
#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define ll long long
using namespace std;
const int N=2e5+10,SZ=5e6+10;
int n,q;
int trie[SZ][27],dep[SZ],fail[SZ],cnt[SZ];
vector<int> E[SZ];vector<pii> ask[SZ];
ll Ans[N];
int tot=0;
ll T[SZ];
int lb(int x){return x&(-x);}
void upd(int x,int v){
    for(int i=x;i<=tot;i+=lb(i)){
        T[i]+=v;
    }
}
ll qry(int x){
    ll res=0;
    for(int i=x;i>0;i-=lb(i)){
        res+=T[i];
    }return res;
}
void insert(string s){
    int now=0,d=0;
    for(auto ed:s){
        int op=ed-'a';
        if(!trie[now][op]) trie[now][op]=++tot;
        d++;now=trie[now][op];dep[now]=d;
    }cnt[now]++;
}
void build(){
    queue<int> q;
    for(int i=0;i<26;i++){
        if(trie[0][i]) q.push(trie[0][i]);
    }
    while(!q.empty()){
        int p=q.front();q.pop();
        //cout<<"bd:"<<dep[p]<<' '<<dep[fail[p]]<<' '<<dep[p]-dep[fail[p]]<<endl;
        for(int i=0;i<26;i++){
            if(trie[p][i]){
                fail[trie[p][i]]=trie[fail[p]][i];
                //cout<<dep[fail[trie[p][i]]]<<' '<<dep[trie[p][i]]<<endl;
                //assert(dep[fail[trie[p][i]]]<dep[trie[p][i]]);
                q.push(trie[p][i]);
            }else{
                trie[p][i]=trie[fail[p]][i];
            }
        }
    }
    for(int i=1;i<=tot;i++){
        E[fail[i]].push_back(i);
    }
}
void dfs(int u,ll c){
    //cout<<"dfs:"<<u<<endl;
    if(dep[u]%2==0&&dep[u]) upd(dep[u],cnt[u]),c+=cnt[u];
    for(auto ed:ask[u]){
        Ans[ed.fi]+=c-qry(ed.se-1);
    }
    for(auto v:E[u]){
        dfs(v,c);
    }
    if(dep[u]%2==0&&dep[u]) upd(dep[u],-cnt[u]),c-=cnt[u];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2,s="";
        cin>>s1>>s2;
        for(int j=0;j<s1.length();j++){
            s+=s1[j];s+=s2[j];
        }insert(s);//cout<<s<<endl;
    }build();
    for(int i=1;i<=q;i++){
        string t1,t2,t="";
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){
            Ans[i]=0;
            //cout<<0<<endl;
        }else{
            int l=0,r=0;
            for(int j=0;j<t1.length();j++){
                if(t1[j]!=t2[j]){l=j;break;}
            }
            for(int j=t1.length()-1;j>=0;j--){
                if(t1[j]!=t2[j]){r=j;break;}
            }l<<=1,r<<=1;
            for(int j=0;j<t1.length();j++){
                t+=t1[j];t+=t2[j];
            }
            //if(i==558) cout<<l<<' '<<r<<' '<<t<<endl;
            int now=0;ll ans=0;
            for(int j=0;j<t.length();j++){
                now=trie[now][t[j]-'a'];
                if((j&1)==0||j<=r) continue;
                ask[now].push_back(mk(i,j-l+1));
                /*for(int x=now;x;x=fail[x]){
                    //if(i==558) cout<<j<<' '<<x<<' '<<dep[x]<<' '<<fail[x]<<' '<<cnt[x]<<endl;
                    if(dep[x]>=j-l+1&&dep[x]%2==0){
                        ans+=cnt[x];
                    }
                }*/
            }//cout<<ans<<endl;
        }
    }dfs(0,0);
    for(int i=1;i<=q;i++){
        cout<<Ans[i]<<'\n';
    }cout.flush();
    return 0;
}