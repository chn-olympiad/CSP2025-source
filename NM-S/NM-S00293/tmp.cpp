#include<iostream>
#include<algorithm>
using ll=long long;
namespace IO{
  const int MAXSIZE=1<<21;
  char pbuf[MAXSIZE],*pb,*pe;
  #define gc() (pb==pe&&(pe==(pb=pbuf)+fread(pbuf,1,MAXSIZE,stdin),pb==pe)?EOF:*pb++)
  using ll=long long;
  inline ll read(){
    ll x=0,f=1;
    char ch=gc();
    while(!isdigit(ch)){
      if(ch=='-')f=-1;
      ch=gc();
    }
    while(isdigit(ch))x=(x<<3)+(x<<1)+ch-'0',ch=gc();
    return x;
  }
}
void file(std::string s){
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
int main(){
  #ifndef LOCAL
  file("");
  #endif 
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}