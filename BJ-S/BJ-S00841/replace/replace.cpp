#include<bits/stdc++.h>
using namespace std;
const int N=5e6+6,K=2e5+5;;
string s1,s2,ts[K];
int n,q,l,r,tr[N][26],tot,k[N],ft,dep[N],fail[N],fa[N],kk[N],m,now,ans,flag;
vector<int>to[K];
int findfail(int x,int c){
    if(fa[x]==0)return 0;
    while(1){
        if(fail[x]==-1)fail[x]=findfail(fa[x],kk[x]);
        if(k[fail[x]]){
            if(!k[x])k[x]=++ft;
            for(int i=0;i<to[fail[x][k]].size();i++){
                to[x[k]].push_back(to[fail[x][k]][i]);
            }
        }
        x=fail[x];
        if(tr[x][c])return tr[x][c];
        if(x==0)return 0;
    }
    return 0;
}
void insert(const string&s,int i){
    int n=0;
    for(auto x:s){
        if(!tr[n][x-'a']){
            tr[n][x-'a']=++tot;
            dep[tot]=dep[n]+1;
        }
        fa[tr[n][x-'a']]=n;
        kk[tr[n][x-'a']]=x-'a';
        n=tr[n][x-'a'];
    }
    if(!k[n])k[n]=++ft;
    to[k[n]].push_back(i);
    return;
}
void dfs(int x){
    if(fail[x]==-1)fail[x]=findfail(fa[x],kk[x]);
    for(int i=0;i<26;i++){
        if(tr[x][i]){
            dfs(tr[x][i]);
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    memset(fail,-1,sizeof fail);
    fail[0]=0;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        ts[i]=s2;
        insert(s1,i);
    }
    dfs(0);
    for(int i=1;i<=q;i++){
        cin>>s1>>s2;
        ans=0;
        m=s1.size();
        if(s1.size()!=s2.size()){
            cout<<0<<'\n';
            continue;
        }
        for(int i=m-1;~i;i--){
            if(s1[i]!=s2[i]){
                r=i;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(s1[i]!=s2[i]){
                l=i;
                break;
            }
        }
        now=0;
        for(int i=0;i<m;i++){
            if(!tr[now][s1[i]-'a'])
                now=findfail(fa[now],s1[i]-'a');
            else now=tr[now][s1[i]-'a'];
            if(k[now]&&i>=r){
                for(int h=0;h<to[k[now]].size();h++){
                    int tf=ts[to[k[now]][h]].size();
                    if(i-tf+1>l)continue;
                    flag=1;
                    for(int p=i-tf+1,j=0;j<tf;p++,j++){
                        if(ts[to[k[now]][h]][j]!=s2[p]){
                            flag=0;
                            break;
                        }
                    }
                    ans+=flag;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}