#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int seat[N][N];
int grade[N * N];
int main(){
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n * m; i ++) {
    scanf("%d", &grade[i]);
  }
  int gradeG = grade[1];
  sort(grade + 1, grade + n * m + 1, greater<int>());
  int t = 1;
  bool flag = false;
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      if (i % 2 != 0 && grade[t] == gradeG) {
        flag = true;
        cout << i << " " << j << endl;
        return 0;
      }
      if (grade[t] == gradeG) {
        flag = true;
      }
      seat[i][j] = grade[t ++];
    }
    if (i % 2 == 0) {
      reverse(seat[i] + 1, seat[i] + m + 1);
    }
    if (flag == true) {
      for (int j = 1; j <= m; j ++) {
        if (seat[i][j] == gradeG) {
          cout << i << " " << j << endl;
          break;
        }
      }
    }
  }
  return 0;
}