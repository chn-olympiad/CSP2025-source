#include <bits/stdc++.h>
using namespace std;
const int N = 1000505;
string s;
int pos, a[N];
int main()
{ 
      freopen("number.in", "r", stdin);
      freopen("number.out","w",stdout);
      cin >> s;
      int n = s.size();
      for (int i = 0; i < n; i++)
          if (s[i] >= '0' && s[i] <= '9') a[pos++] = s[i] - '0' ;
      sort(a, a + pos);
      for (int i = pos - 1; i >= 0; i--)
          cout << a[i];
      return 0;
}
