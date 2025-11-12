#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> p;
  {
    string v = "";
        cin >> v;
    for(char i : v)
      if(i >= '0' && i <= '9') {
        p.push_back(int(i - '0'));
      }
  }
  sort(p.begin(), p.end(), [](int a, int b)
  {
    return a > b;
  });
  for(int i : p)
  {
    cout << i;
  }
  return 0;
}
