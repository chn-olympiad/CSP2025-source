#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;
const int N=200005,M=5000005;
char s[M],t[M];
const int B=5027657,P=998244389;
int Hash(char *s,int l,int r){
    int res=0;
    for(int i=l;i<=r;i++)
        res=(1ll*res*B+s[i])%P;
    return res;
}
map<PII,int>pos;
int tot;
int Cnt[N];
struct Trie{
    int sn[M][27];
    int fail[M];
    int ed[M];
    int rt[N];
    int cnt;
    int New(){
        return ++cnt;
    }
    void insert(char *s,int u,int n){
        for(int i=1;i<=n;i++){
            int now=(s[i]=='#'?26:s[i]-'a');
            if(!sn[u][now]) sn[u][now]=++cnt;
            u=sn[u][now];
        }
        ed[u]++;
    }
    void bfs(int s){
        queue<int>q;
        fail[s]=s;
        for(int i=0;i<=26;i++){
            if(sn[s][i]){
                q.push(sn[s][i]);
                fail[sn[s][i]]=s;
                ed[sn[s][i]]+=ed[s];
            }
            else sn[s][i]=s;
		}
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0;i<=26;i++){
                if(sn[u][i]){
                    fail[sn[u][i]]=sn[fail[u]][i];
                    ed[sn[u][i]]+=ed[fail[sn[u][i]]];
                    q.push(sn[u][i]);
                }
                else sn[u][i]=sn[fail[u]][i];
            }
        }
    }
    int query(char *s,int u,int n){
        int res=ed[u];
        for(int i=1;i<=n;i++){
            int now=(s[i]=='#'?26:s[i]-'a');
            u=sn[u][now];
            res+=ed[u];
        }
        return res;
    }
}T;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        scanf("%s",t+1);
        int m=strlen(s+1);
        bool bz=0;
        for(int j=1;j<=m;j++)
            if(s[j]!=t[j]) bz=1;
        if(!bz) continue;
        int l=0,r=0;
        for(int j=1;j<=m;j++)
            if(s[j]!=t[j]){
                l=j;
                break;
            }
        for(int j=m;j>=1;j--)
            if(s[j]!=t[j]){
                r=j;
                break;
            }
        PII cur={Hash(s,l,r),Hash(t,l,r)};
        if(pos.find(cur)==pos.end()){
            pos[cur]=++tot;
            T.rt[tot]=T.New();
        }
        int now=pos[cur];
        for(int j=l+1,k=r+1;k<=m;j++,k++)
            s[j]=s[k];
        s[l]='#';
        m=m-(r-l);
        T.insert(s,T.rt[now],m);
    }
    for(int i=1;i<=tot;i++)
    	T.bfs(T.rt[i]);
    for(int i=1;i<=q;i++){
        scanf("%s",s+1);
        scanf("%s",t+1);
        int m=strlen(s+1);
        int l=0,r=0;
        for(int j=1;j<=m;j++)
            if(s[j]!=t[j]){
                l=j;
                break;
            }
        for(int j=m;j>=1;j--)
            if(s[j]!=t[j]){
                r=j;
                break;
            }
        PII cur={Hash(s,l,r),Hash(t,l,r)};
        if(pos.find(cur)==pos.end()){
            printf("0\n");
            continue;
        }
        int now=pos[cur];
        for(int j=l+1,k=r+1;k<=m;j++,k++)
            s[j]=s[k];
        s[l]='#';
        m=m-(r-l);
        printf("%d\n",T.query(s,T.rt[now],m));
    }
}