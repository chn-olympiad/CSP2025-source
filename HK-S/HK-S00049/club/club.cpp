#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int i, j, n;
  cin >> n;
  int a[n][3];
  vector<int> v, v2, v3;
  for(i=0; i<n; i++)
  {
      for(j=0; j<3; j++) cin >> a[i][j];
  }
  for(i=0; i<n; i++)
  {
      if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]) v.push_back(i);
      else if(a[i][1]>=a[i][2]) v2.push_back(i);
      else v3.push_back(i);
  }
  if(v.size()>n/2)
  {
    vector<pair<int, int>> tmp;
    for(i=0; i<v.size(); i++) tmp.push_back({a[v[i]][0]-max(a[v[i]][1], a[v[i]][2]), v[i]});
    v.clear();
    sort(tmp.begin(), tmp.end());
    for(i=0; i<tmp.size()-n/2; i++)
    {
        if(a[tmp[i].second][1]>=a[tmp[i].second][2]) v2.push_back(tmp[i].second);
        else v3.push_back(tmp[i].second);
    }
    for(i=tmp.size()-n/2; i<tmp.size(); i++) v.push_back(tmp[i].second);
  }
  else if(v2.size()>n/2)
  {   
    vector<pair<int, int>> tmp;
    for(i=0; i<v2.size(); i++) tmp.push_back({a[v2[i]][1]-max(a[v2[i]][0], a[v2[i]][2]), v2[i]});
    v2.clear();
    sort(tmp.begin(), tmp.end());
    for(i=0; i<tmp.size()-n/2; i++)
    {
      if(a[tmp[i].second][0]>=a[tmp[i].second][2]) v.push_back(tmp[i].second);
      else v3.push_back(tmp[i].second);
    }
    for(i=tmp.size()-n/2; i<tmp.size(); i++) v2.push_back(tmp[i].second);
  }
  else if(v3.size()>n/2)
  {
    vector<pair<int, int>> tmp;
    for(i=0; i<v3.size(); i++) tmp.push_back({a[v3[i]][2]-max(a[v3[i]][0], a[v3[i]][1]), v3[i]});
    v3.clear();
    sort(tmp.begin(), tmp.end());
    for(i=0; i<tmp.size()-n/2; i++)
    {
      if(a[tmp[i].second][0]>=a[tmp[i].second][1]) v.push_back(tmp[i].second);
      else v2.push_back(tmp[i].second);
    }
    for(i=tmp.size()-n/2; i<tmp.size(); i++) v3.push_back(tmp[i].second);
  }
  int ans = 0;
  for(i=0; i<v.size(); i++) ans += a[v[i]][0];
  for(i=0; i<v2.size(); i++) ans += a[v2[i]][1];
  for(i=0; i<v3.size(); i++) ans += a[v3[i]][2];
  cout << ans << "\n";
}

int main()
{
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}