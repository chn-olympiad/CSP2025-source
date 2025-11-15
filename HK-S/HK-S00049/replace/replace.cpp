#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int i, j, l, k, n, q, l1=0, l2=0;
  cin >> n >> q;
  pair<string, string> s[n], t[q];
  for(i=0; i<n; i++) 
  {
    cin >> s[i].first >> s[i].second;
    l1 += s[i].first.length() + s[i].second.length();
  }
  for(i=0; i<q; i++)
  {
    cin >> t[i].first >> t[i].second;
    l2 += t[i].first.length() + t[i].second.length();
  }
  if(l1<=2000 && l2<=2000)
  {
    for(l=0; l<q; l++)
    {
      long long int ans = 0;
      for(i=0; i<n; i++)
      {
        for(j=0; j<t[l].first.length()-s[i].first.length()+1; j++)
        {
          string tmp = t[l].first;
          if(s[i].first!=t[l].first.substr(j, s[i].first.length())) continue;
          for(k=0; k<s[i].second.length(); k++) t[l].first[j+k] = s[i].second[k];
          if(t[l].first==t[l].second) ans++;
          t[l].first = tmp;
        }
      }
      cout << ans << "\n";
    }
  }
  else
  {
    pair<int, int> cnt[n];
    int pos[n];
    for(i=0; i<n; i++)
    {
      int tmp, tmp2;
      for(j=0; j<s[i].first.length(); j++)
      {
        if(s[i].first[j]=='b')
        {
          cnt[i].first = j;
          cnt[i].second = s[i].first.length() - j - 1;
          tmp = j;
          break;
        }
      }
      for(j=0; j<s[i].second.length(); j++)
      {
        if(s[i].second[j]=='b')
        {
          tmp2 = j;
          break;
        }
      }
      pos[i] = tmp - tmp2;
    }
    for(i=0; i<q; i++)
    {
      int tmp, tmp2, tmp3, tmp4;
      for(j=0; j<t[i].first.length(); j++)
      {
        if(t[i].first[j]=='b')
        {
          tmp = j;
          tmp2 = t[i].first.length() - j - 1;
          tmp3 = j;
          break;
        }
      }
      for(j=0; j<t[i].second.length(); j++)
      {
        if(t[i].second[j]=='b')
        {
          tmp4 = j;
          break;
        }
      }
      int ans = 0;
      for(j=0; j<n; j++)
      {
        if(tmp>=cnt[j].first && tmp2>=cnt[j].second && pos[j]==tmp3-tmp4) ans++;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}