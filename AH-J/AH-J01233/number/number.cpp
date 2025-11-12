#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=15;
string s;
LL cnt[N];
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>s;
  for(LL i=0;i<s.size();i++)
    if(isdigit(s[i])) cnt[s[i]-'0']++;
  for(LL i=9;i>=0;i--)
    if(cnt[i])
      for(LL j=1;j<=cnt[i];j++) printf("%lld",i);
  return 0;
}
