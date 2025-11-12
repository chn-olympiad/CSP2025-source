#include<bits/stdc++.h>
using namespace std;
int n,m,id[400005],tr1[5000005][27],cnt1=1,head[5000005],nxt[400005],tr2[5000005][27],cnt2=1,dfn[5000005],d,sz[5000005],tr[5000005],ans[200005];
string s1[400005],s2[400005],t1,t2,s;
void insert1(string s,int p){
  int pos=1;
  for(int i=0;i<s.size();i++){
    if(!tr1[pos][s[i]-'a'])tr1[pos][s[i]-'a']=++cnt1;
    pos=tr1[pos][s[i]-'a'];
  }
  nxt[p]=head[pos],head[pos]=p;
}
void insert2(string s,int p){
  int pos=1;
  for(int i=0;i<s.size();i++){
    if(!tr2[pos][s[i]-'a'])tr2[pos][s[i]-'a']=++cnt2;
    pos=tr2[pos][s[i]-'a'];
  }
  id[p]=pos;
}
void add(int x,int k){
  for(;x<=cnt2;x+=x&-x)tr[x]+=k;
}
int query(int x,int ans=0){
  for(;x;x-=x&-x)ans+=tr[x];
  return ans;
}
void dfs2(int pos){
  dfn[pos]=++d,sz[pos]=1;
  for(int i=0;i<=26;i++)if(tr2[pos][i])dfs2(tr2[pos][i]),sz[pos]+=sz[tr2[pos][i]];
}
void dfs1(int pos){
  for(int i=head[pos];i;i=nxt[i])if(i>m)add(dfn[id[i]],1),add(dfn[id[i]]+sz[id[i]],-1);
  for(int i=head[pos];i;i=nxt[i])if(i<=m)ans[i]=query(dfn[id[i]]);
  for(int i=0;i<=26;i++)if(tr1[pos][i])dfs1(tr1[pos][i]);
  for(int i=head[pos];i;i=nxt[i])if(i>m)add(dfn[id[i]],-1),add(dfn[id[i]]+sz[id[i]],1);
}
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0),cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
  for(int i=1;i<=m;i++){
    cin>>t1>>t2;
    int l=-1,r=-1;
    for(int j=0;j<t1.size();j++){
      if(t1[j]!=t2[j]){
        if(l==-1)l=j;
        r=j;
      }
    }
    s.clear();
    for(int j=0;j<l;j++)s+=t1[j];
    s+='{';
    for(int j=l;j<=r;j++)s+=t1[j];
    for(int j=l;j<=r;j++)s+=t2[j];
    reverse(s.begin(),s.end()),insert1(s,i),s.clear();
    for(int j=r+1;j<t1.size();j++)s+=t1[j];
    insert2(s,i);
  }
  for(int i=1;i<=n;i++){
    if(s1[i]==s2[i])continue;
    int l=-1,r=-1;
    for(int j=0;j<s1[i].size();j++){
      if(s1[i][j]!=s2[i][j]){
        if(l==-1)l=j;
        r=j;
      }
    }
    s.clear();
    for(int j=0;j<l;j++)s+=s1[i][j];
    s+='{';
    for(int j=l;j<=r;j++)s+=s1[i][j];
    for(int j=l;j<=r;j++)s+=s2[i][j];
    reverse(s.begin(),s.end()),insert1(s,m+i),s.clear();
    for(int j=r+1;j<s1[i].size();j++)s+=s1[i][j];
    insert2(s,m+i);
  }
  dfs2(1),dfs1(1);
  for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
  return 0;
}
