#include<bits/stdc++.h>
#define int long long
using std::vector;
using std::queue;
using std::cin;
using std::cout;
using std::ios;
using std::string;

int ch[6000005][28],idx=1;
int fail[6000005],flag[6000005],ff[6000005];
int n,q,Q;
vector<int> roots;
vector<int> lazy;
void dfs(int root){
  fail[root]=root;
  queue<int> q;
  for (int i=0;i<28;i++){
    if (!ch[root][i]){
      ch[root][i]=root;
      continue;
    }
    fail[ch[root][i]]=root;
    q.push(ch[root][i]);
  }
  while (!q.empty()){
    int u=q.front();q.pop();
    for (int i=0;i<28;i++){
      if (ch[u][i]){
	fail[ch[u][i]]=ch[fail[u]][i];
	//flag[ch[u][i]+=flag[ch[fail[u]][i]];
	q.push(ch[u][i]);
      }
      else ch[u][i]=ch[fail[u]][i];
    }
  }
}
void solve(){
  cin>>n>>q;
  for (int i=1;i<=n;i++){
    string a,b;cin>>a>>b;
    int l=0,r=a.length()-1;
    while (l<a.length()&&a[l]==b[l])++l;
    if (l==a.length())continue;
    while (r>=0&&a[r]==b[r])--r;
    int now=1;
    for (int j=l;j<=r;j++){
      if (!ch[now][a[j]-'a'])ch[now][a[j]-'a']=++idx;
      now=ch[now][a[j]-'a'];
    }
    if (!ch[now][26])ch[now][26]=++idx;
    now=ch[now][26];
    for (int j=l;j<=r;j++){
      if (!ch[now][b[j]-'a'])ch[now][b[j]-'a']=++idx;
      now=ch[now][b[j]-'a'];
    }
    if (!ch[now][27]){
      ch[now][27]=++idx;
      roots.push_back(idx);
    }
    now=ch[now][27];
    for (int j=0;j<l;j++){
      if (!ch[now][a[j]-'a'])ch[now][a[j]-'a']=++idx;
      now=ch[now][a[j]-'a'];
    }
    if (!ch[now][26]){
      ch[now][26]=++idx;
    }
    now=ch[now][26];
    for (int j=r+1;j<a.length();j++){
      if (!ch[now][a[j]-'a'])ch[now][a[j]-'a']=++idx;
      now=ch[now][a[j]-'a'];
    }
    flag[now]++;
    ff[now]=1;
  }
  for (int root:roots){
    dfs(root);
  }
  while (q--){
    string a,b;cin>>a>>b;
    int l=0,r=a.length()-1;
    while (l<a.length()&&a[l]==b[l])++l;
    if (l==a.length()){
      cout<<"0\n";
      continue;
    }
    while (r>=0&&a[r]==b[r])--r;
    int now=1;
    for (int i=l;i<=r;i++)now=ch[now][a[i]-'a'];
    now=ch[now][26];
    for (int i=l;i<=r;i++)now=ch[now][b[i]-'a'];
    now=ch[now][27];
    if (now==0){
      cout<<"0\n";
    }
    else{
      int ans=0,root=now;
      for (int i=0;i<l;i++){
	now=ch[now][a[i]-'a'];
	int p=now;
	while (p!=root){
	  if (ff[p]==-1)break;
	  ans+=flag[p];
	  ff[p]=-1;
	  p=fail[p];
	}
      }
      now=ch[now][26];
      int p=now;
	while (p!=root){
	  if (ff[p]==-1)break;
	  ans+=flag[p];
	  ff[p]=-1;
	  p=fail[p];
	}
      for (int i=r+1;i<a.length();i++){
	now=ch[now][a[i]-'a'];
	int p=now;
	while (p!=root){
	  if (ff[p]==-1)break;
	  ans+=flag[p];
	  ff[p]=-1;
	  p=fail[p];
	}
      }
      cout<<ans<<"\n";
      now=root;
      for (int i=0;i<l;i++){
	now=ch[now][a[i]-'a'];
	int p=now;
	while (p!=root){
	  if (ff[p]==1)break;
	  if (ff[p]==-1)ff[p]=1;
	  p=fail[p];
	}
      }
      now=ch[now][26];
      while (p!=root){
	  if (ff[p]==1)break;
	  if (ff[p]==-1)ff[p]=1;
	  p=fail[p];
	}
      for (int i=r+1;i<a.length();i++){
	now=ch[now][a[i]-'a'];
	while (p!=root){
	  if (ff[p]==1)break;
	  if (ff[p]==-1)ff[p]=1;
	  p=fail[p];
	}
      }
    }
  }
}
signed main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
  return 0;
}
