#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  long long n,q;
  cin >> n >> q;
  long long s[n+5][2];
  for (int i=1;i<=n;i++)
  {
    cin >> s[i][0]>>s[i][1];
  }
  long long t[q+5][2];
  for(int i =1;i<=q;i++)
  {
  cin >> t[i][0]>>t[i][1];
  }
  return 0;
}
