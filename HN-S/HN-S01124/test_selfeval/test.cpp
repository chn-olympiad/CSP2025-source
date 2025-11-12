#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL_IO
#include <iostream>
#else
#include <fstream>

const string kFile = "test";
ifstream cin(kFile + ".in");
ofstream cout(kFile + ".out");
#endif

int a, b;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> a >> b;
  cout << a + b;
  return 0;
}