// shinzanmonoWYB@hs2z
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using ll=long long;
const int sz=2e5+10;
const int msz=5e6+10;
const int base=151;
const ll mod=1e9+7;
void file(std::string s){
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
ll hasha[msz],hashb[msz],sa[sz],sb[sz],len[sz],pows[msz];
ll get(ll *hash,int l,int r){
  return (hash[r]-hash[l-1]*pows[r-l+1]%mod+mod)%mod;
}
bool special(std::string &a){
  return std::count(a.begin(),a.end(),'b')==1&&std::count(a.begin(),a.end(),'a')==a.size()-1;
}
std::map<int,std::vector<std::pair<int,int>>>point;
int main(){
  file("replace");
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,q;
  std::cin>>n>>q;
  bool flag=true;
  for(int i=1;i<=n;i++){
    std::string s,t;
    std::cin>>s>>t,len[i]=s.length();
    for(int j=0;j<len[i];j++)
      sa[i]=(sa[i]*base+s[j])%mod,sb[i]=(sb[i]*base+t[j])%mod;
    if(special(s)&&special(t)){
      int pa=0,pb=0;
      while(s[pa]!='b')pa++;
      while(s[pb]!='b')pb++;
      point[pa-pb].emplace_back(pa+1,n-pa-1);
    }else flag=false;
  }
  for(int T=1;T<=q;T++){
    std::string s,t;
    int m,ans=0;
    std::cin>>s>>t,m=s.size(),s=" "+s,t=" "+t;
    pows[0]=1;
    for(int i=1;i<=m;i++){
      hasha[i]=(hasha[i-1]*base+s[i])%mod;
      hashb[i]=(hashb[i-1]*base+t[i])%mod;
      pows[i]=pows[i-1]*base%mod;
    }
    int l=1,r=m;
    while(s[l]==t[l])l++;
    while(s[r]==t[r])r--;
    int ll=r-l+1;
    if(flag&&special(s)&&special(t)){
      int a=l,b=r;
      if(t[l]=='b')std::swap(a,b);
      int d=a-b;
      for(auto [x,y]:point[d])if(x<=a&&y<=m-a)ans++;
      std::cout<<ans<<"\n";
    }
    for(int j=1;j<=n;j++){
      if(len[j]<ll)continue;
      for(int i=r-len[j]+1;i<=l&&i+len[j]-1<=m;i++){
        if(get(hasha,i,i+len[j]-1)!=sa[j]||get(hashb,i,i+len[j]-1)!=sb[j])continue;
        ans++;
        break;
      }
    }
    std::cout<<ans<<"\n";
  }
  return 0;
}