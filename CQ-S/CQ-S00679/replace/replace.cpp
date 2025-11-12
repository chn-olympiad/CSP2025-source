#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2.1e5,B=6907,P=1e9+9,B2=10007,P2=998244353;
inline int add(int x,int y){
  int s=x+y; if(s>=P)s-=P; return s;
}
inline int add2(int x,int y){
  int s=x+y; if(s>=P2)s-=P2; return s;
}
class hashing{
  private:
    int n;
    vector<int> p,h;
    vector<int> p2,h2;
  public:
    hashing(vector<int> a):n(a.size()),p(n+1),h(n),p2(n+1),h2(n){
      for(int i=p[0]=1;i<=n;i++)
        p[i]=1ll*p[i-1]*B%P;
      for(int i=0;i<n;i++)
        h[i]=add(i?1ll*h[i-1]*B%P:0,a[i]+1);
      for(int i=p2[0]=1;i<=n;i++)
        p2[i]=1ll*p2[i-1]*B2%P2;
      for(int i=0;i<n;i++)
        h2[i]=add2(i?1ll*h2[i-1]*B2%P2:0,a[i]+1);
    }
    ll val(int l,int r){
      if(l>r)return 0;
      int x=add(h[r],l?P-1ll*h[l-1]*p[r-l+1]%P:0),
        y=add2(h2[r],l?P2-1ll*h2[l-1]*p2[r-l+1]%P2:0);
      return 1ll*x*P2+y;
    }
};
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n,q; cin>>n>>q;
  unordered_map<ll,int> mx,my;
  vector<pair<int,int> > s;
  for(int i=0;i<n;i++){
    string a,b; cin>>a>>b;
    if(a==b)continue;
    int m=a.length(),l=-1;
    for(int j=0;j<m;j++)
      if(a[j]!=b[j]){l=j; break;}
    vector<int> mp(m);
    for(int j=0;j<m;j++)
      mp[j]=(a[j]-97)*26+(b[j]-97);
    hashing h(mp);
    ll hx=h.val(l,m-1),hy=h.val(0,l-1);
    int px=-1,py=-1;
    if(mx.find(hx)!=mx.end())px=mx[hx];
    else px=mx.size(),mx[hx]=px;
    if(my.find(hy)!=my.end())py=my[hy];
    else py=my.size(),my[hy]=py;
    s.emplace_back(px,py);
  }
  vector<vector<int> > v(n);
  int B=sqrt(n);
  for(auto w:s){
    int x,y; tie(x,y)=w;
    v[x].emplace_back(y);
  }
  for(auto &w:v)sort(w.begin(),w.end());
  vector<vector<int> > ex(n);
  {
    int c=my.size();
    for(auto &w:v){
      vector<int> ps;
      for(int i=1;i<w.size();i++)
        if(w[i]==w[i-1])ps.emplace_back(i);
      for(int i:ps)ex[w[i]].emplace_back(c),w[i]=c++;
    }
  }
  for(auto &w:v)sort(w.begin(),w.end());
  vector<int> ebp,eid(n,-1);
  for(int i=0;i<n;i++)
    if(ex[i].size()>B)eid[i]=ebp.size(),ebp.emplace_back(i);
  vector<bitset<N> > ebs(ebp.size());
  for(int i=0;i<ebp.size();i++)
    for(int j:ex[ebp[i]])ebs[i].set(j);
  vector<int> bp,id(n,-1);
  for(int i=0;i<n;i++)
    if(v[i].size()>B)id[i]=bp.size(),bp.emplace_back(i);
  vector<bitset<N> > bs(bp.size());
  for(int i=0;i<bp.size();i++)
    for(int j:v[bp[i]])bs[i].set(j);
  bitset<N> b2;
  while(q--){
    string a,b; cin>>a>>b,b2.reset();
    if(a.length()!=b.length()){cout<<"0\n"; continue;}
    int m=a.length(),l=-1,r=-1;
    for(int j=0;j<m;j++)
      if(a[j]!=b[j]){l=j; break;}
    for(int j=0;j<m;j++)
      if(a[j]!=b[j])r=j;
    vector<int> mp(m);
    for(int j=0;j<m;j++)
      mp[j]=(a[j]-97)*26+(b[j]-97);
    hashing h(mp);
    for(int j=l;~j;j--){
      ll hy=h.val(j,l-1);
      if(my.find(hy)!=my.end()){
        int py=my[hy];
        b2.set(py);
        if(~eid[py])b2|=ebs[eid[py]];
        else for(int k:ex[py])b2.set(k);
      }
    }
    ll c=0;
    auto stats=[&](int x)->int{
      if(~id[x])return (bs[id[x]]&b2).count();
      int c=0;
      for(int i:v[x])if(b2.test(i))c++;
      return c;
    };
    for(int j=r;j<m;j++){
      ll hx=h.val(l,j);
      if(mx.find(hx)!=mx.end())c+=stats(mx[hx]);
    }
    cout<<c<<'\n';
  }
  return 0;
}