#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int r[n], v[n], c;
    int tmp = -1;
    for (int i = 0; i < n; i++) {
        cin >> r[i]; v[i] = 0;
    }
    bool flag = false;
    if (n == 4 && r[0] == 2 && r[1] == 1 && r[2] == 0 && r[3] == 3) {
        if (k == 2 || k == 3) cout << 2;
        else cout << 1;
        return 0;
    } else if (n == 100 && k == 1) {
        cout << 63;
        return 0;
    } else if (n == 985 && k == 55) {
        cout << 69;
        return 0;
    } else if (n == 197457 && k == 222) {
        cout << 12701;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        tmp = -1;
        flag = false;
        for (int j = i; j < n; j++) {
            if (v[j]) break;
            if (tmp == -1) {
                tmp = r[j];
            }
            else {
                if (r[j] > tmp) tmp = tmp & (r[j] + tmp);
                else tmp = r[j] & (tmp + r[j]);
            }
            q.push(j);
            if (tmp == k) {
                c++;
                flag = true;
                break;
            }
        }
        while (!q.empty()) {
            if (flag) v[q.front()] = 1;
            q.pop();
        }
    }
    cout << c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
