#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<numeric>
#include<utility>
#include<map>
#include<queue>
using namespace std;
const int P=139;
typedef unsigned long long ULL;
int n,q;
long long ans;
string s1,s2;
int len[200005];
pair<ULL,ULL> h[200005];
ULL power[5000005],h1[5000005],h2[5000005];
int main() {
  freopen("replace.in","r",stdin);
  freopen("replace.out","w+",stdout);
  ios::sync_with_stdio(0);
  cout.tie(0);
  power[0]=1;
  for(int i=1;i<=5E06;i++)
    power[i]=power[i-1]*P;
  cin>>n>>q;
  auto hash=[&](string s) {
    ULL res=0;
    for(int i=0;i<s.length();i++)
      res=res*P+s[i];
    return res;
  };
  for(int i=1;i<=n;i++) {
    cin>>s1>>s2;
    len[i]=s1.length();
    h[i]=make_pair(hash(s1),hash(s2));
  }
  auto getHash=[&](ULL h[],int l,int r) {
    if(r<l)
      return 0ull;
    return h[r]-h[l-1]*power[r-l+1];
  };
  while(q--) {
    cin>>s1>>s2;
    if(s1.length()^s2.length()) {
      cout<<0<<'\n';
      continue;
	}
    for(int i=0;i<s1.length();i++)
      h1[i+1]=h1[i]*P+s1[i];
    for(int i=0;i<s2.length();i++)
      h2[i+1]=h2[i]*P+s2[i];
    ans=0;
    for(int i=1;i<=n;i++)
      for(int j=0;j+len[i]-1<s1.length();j++) {
        if(getHash(h1,j+1,j+len[i])==h[i].first && getHash(h2,j+1,j+len[i])==h[i].second && getHash(h1,1,j)==getHash(h2,1,j) && getHash(h1,j+len[i]+1,s1.length())==getHash(h2,j+len[i]+1,s2.length())) {
          ans++;
		}
	  }
	cout<<ans<<'\n';
  }
}

