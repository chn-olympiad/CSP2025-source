#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, a[N], my_id, num_of_p, my_score;

bool cmp(int a, int b) { return a > b; }

int main() {
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
  cin >> n >> m;
  num_of_p = n * m;
  for (int i = 1; i <= num_of_p; i++) cin >> a[i];
  my_score = a[1];
  sort(a + 1, a + num_of_p + 1, cmp);
  for (int i = 1; i <= num_of_p; i++)
    if (a[i] == my_score) {
      my_id = i;
      break;
    }
  // cout << my_id << endl;
  int lie = ceil(my_id * 1.0 / n);
  int hang = my_id - (lie - 1) * n;
  cout << lie << ' ';
  if (lie % 2 == 1)
    cout << hang;
  else
    cout << n - hang + 1;
  return 0;
}