#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  int n,q;
  string t1,t2;
  cin>>n>>q;
  vector<pair<string,sting>> s(n);
  for (auto &[s1,s2]:s)
    cin>>s1>>s2;
  while (q--)
  {
    int ans=0;
    cin>>t1>>t2;
    for (auto [s1,s2]:s)
    {
      auto calc=[&](string s)
      {
        vector<int> pi(s.size());
        for (size_t i=1;i<s.size();i++)
        {
          int j=pi[i-1];
          while (j&&s[j]!=s[i])
            j=pi[j-1];
          pi[i]=j;
          if (s[j]==s[i]) pi[i]++;
        }
        return pi;
      }
      string t=s1+'#'+t1;
      vector<int> pi=calc(t);
      vector<size_t> pos;
      for (size_t i=s1.size()-1;i<t1.size();i++)
        if (pi[i+s1.size()+1]==s1.size()) pos.push_back(i-s1.size()+1);
      for (auto i:pos)
      {
        size_t j=i+s1.size(),len=t1.size()-j;
        if (t1.substr(0,i)+s2+t1.substr(j,len)==t2) ans++;
      }
    }
    cout<<ans<<'\n';
  }
}
