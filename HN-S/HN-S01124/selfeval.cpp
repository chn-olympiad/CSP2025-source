#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  string s;
  int n, l;
  cin >> s >> n >> l;
  auto exec = [&](const string &cmd) {
    return system(("cd " + s + " && ulimit -v " + to_string(l * 1024) + " && ulimit -s " + to_string(l * 1024) + " && " + cmd).c_str());
  };
  exec("g++ " + s + ".cpp -o " + s + " -std=c++14 -O2 -static -Wall -Wextra -Wconversion -Wshadow");
  for (int i = 1; i <= n; ++i) {
    exec("cp " + s + to_string(i) + ".in " + s + ".in");
    cerr << "Running Test #" << i << endl;
    int st = clock();
    exec("./" + s);
    int ed = clock();
    cerr << "Over Test #" << i << ' ' << fixed << 1.0 * (ed - st) / CLOCKS_PER_SEC << 's' << endl;
    if (exec("diff " + s + to_string(i) + ".ans " + s + ".out -Z")) {
      cerr << "Wa Test #" << i << endl;
      break;
    }
    cerr << "Ok Test #" << i << endl;
  }
  return 0;
}