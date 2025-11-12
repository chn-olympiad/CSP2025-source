//what???AC zi dong ji???
#include<bits/stdc++.h>
using namespace std;
const int N=2e5,L=5e6;
map<string,int>mp;
int n,q,cnt,fi,la,tot,ans;
string s1[N+5],s2[N+5],t1,t2,nw;
struct ti{
  int nx1[27],nx2;// nwxt and fail
}t[L+N*2+5];
int a[L+N*2+5],dl[L+N*2+5],fa[L+N*2+5],c[L+N*2+5];
void inline insert(int x,int id,int nw){
   if(nw==s1[id].size()){a[x]++;return ;}
   if(nw!=fi){
   int nx=t[x].nx1[s1[id][nw]-'a'];
   if(nx==0){tot++;t[x].nx1[s1[id][nw]-'a']=tot;}
   nx=t[x].nx1[s1[id][nw]-'a'];fa[nx]=x;
   c[nx]=s1[id][nw]-'a';
   insert(nx,id,nw+1);
   }
   else{
   int nx=t[x].nx1[26];
   if(nx==0){tot++;t[x].nx1[26]=tot;}
   nx=t[x].nx1[26];fa[nx]=x;
   c[nx]=26;
   insert(nx,id,la+1);
   }
}
void inline bfs(int X){
   int bg=1,ed=1;dl[bg]=X;
   while(bg<=ed){
   
   int x=dl[bg];bg++;
   for(int i=0;i<=26;i++)if(t[x].nx1[i]!=0){ed++;dl[ed]=t[x].nx1[i];}
   int qaq=t[fa[x]].nx2;
   while(qaq!=0&&qaq!=X&&t[qaq].nx1[c[x]]==0){qaq=t[qaq].nx2;}
   if(qaq==0||x==t[qaq].nx1[c[x]]){t[x].nx2=X;a[x]+=a[t[x].nx2];}
   else t[x].nx2=t[qaq].nx1[c[x]],a[x]+=a[t[x].nx2];
   }
}
void inline g_a(int bg,int x,int nw){
//cout<<bg<<" "<<x<<" "<<nw<<"qwqwqwq"<<" "<<a[x]<<"\n";
 // cerr<<bg<<" "<<x<<" "<<nw<<" "<<t1.size()<<"\n";
  ans+=a[x];if(nw==t1.size())return ;
  if(nw!=fi){
  while(x!=bg&&x!=0&&t[x].nx1[t1[nw]-'a']==0){x=t[x].nx2;}
  x=t[x].nx1[t1[nw]-'a'];
  if(x==0)x=bg;
  g_a(bg,x,nw+1);
  }
  else{
  while(x!=bg&&x!=0&&t[x].nx1[26]==0){x=t[x].nx2;}
  x=t[x].nx1[26];
  if(x==0)x=bg;
  g_a(bg,x,la+1); 
  }
}
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>q;tot=n;
  for(int i=1;i<=n;i++){
  cin>>s1[i]>>s2[i];
  nw="@";fi=-1;
  for(int j=0;j<s1[i].size();j++)
  if(s1[i][j]!=s2[i][j]){la=j;if(fi==-1)fi=j;}
  if(fi==-1)continue;
  for(int j=fi;j<=la;j++){nw+=s1[i][j];nw+=s2[i][j];}
 // cout<<fi<<" "<<la<<" "<<nw<<"\n";
  if(mp[nw]==0){cnt++;mp[nw]=cnt;}int x=mp[nw];
  insert(x,i,0);
  }
 // return 0;
  for(int i=1;i<=cnt;i++)bfs(i);
  /*
  for(int i=1;i<=tot;i++){
  cout<<i<<"qaq "<<c[i]<<" "<<fa[i]<<" "<<t[i].nx2<<" "<<a[i]<<"\n";
  for(int j=0;j<=26;j++)
  if(t[i].nx1[j]!=0)
  cout<<j<<" "<<t[i].nx1[j]<<"\n";
  }
  */
  for(int i=1;i<=q;i++){
  cin>>t1>>t2;fi=-1;nw="@";
  for(int j=0;j<t1.size();j++)
  if(t1[j]!=t2[j]){la=j;if(fi==-1)fi=j;}
  for(int j=fi;j<=la;j++){nw+=t1[j];nw+=t2[j];}
  if(mp[nw]==0){cout<<0<<"\n";continue;}int x=mp[nw];
  ans=0;
  g_a(x,x,0);
  cout<<ans<<"\n";
  }
}
