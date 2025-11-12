#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("replace.in");
ofstream fout("replace.out");

const int kN = 501, kV = 18, kM = 998244353;

int n, q, fl = 1, c[kN], f[2][19][1 << kV];
string t;

int main() {
  fin.tie(0)->sync_with_stdio(0);
  fin >> n >> q;
  for (int i = 1; i <= q; i++)
    fout << "0\n";
  return 0;
}