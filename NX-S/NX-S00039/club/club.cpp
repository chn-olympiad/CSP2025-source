#include <bits/stdc++.h>
using namespace std;
struct p_ {
    int x;
    int y;
    int z;
    int flag;
};
p_ a[100009], b[100009];
bool cmp_x (p_ p, p_ q) {
    if (p.x == q.x) {
        if (p.y == q.y) {
            return p.z < q.z;
        }
        return p.y < q.y;
    }
    return p.x > q.x;
}
bool cmp_y (p_ p, p_ q) {
    if (p.y == q.y) {
        if (p.z == q.z) {
            return p.x < q.x;
        }
        return p.z < q.z;
    }
    return p.y > q.y;
}
bool cmp_z (p_ p, p_ q) {
    if (p.z == q.z) {
        if (p.x == q.x) {
            return p.y < q.y;
        }
        return p.x < q.x;
    }
    return p.z > q.z;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n, max_ = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].z;
            b[i].x = a[i].x;
            b[i].y = a[i].y;
            b[i].z = a[i].z;
        }
        int sum = 0, cnt = 1, cnt_ = 0, f1 = 0, f2 = 0, f3 = 0;
        for (int i = 0; i < n; i++) {
            if (b[i].x > b[i].y && b[i].x > b[i].z) {
                b[i].flag = 1;
                f1++;
            } else if (b[i].y > b[i].x && b[i].y > b[i].z) {
                b[i].flag = 2;
                f2++;
            } else if (b[i].z > b[i].x && b[i].z > b[i].y) {
                b[i].flag = 3;
                f3++;
            }
        }
        if (f1 > n/2) {
            for (int i = 0; i < n; i++) {
                if (b[i].flag == 2 || b[i].flag == 3) {
                    sum += max(b[i].y, b[i].z);
                    b[i].flag = 0;
                    b[i].x = 0;
                }
            }
            sort(b, b + n, cmp_x);
            for (int i = 0; i < n; i++) {
                if (cnt <= n/2) {
                    sum += b[i].x;
                    b[i].flag = 0;
                    cnt++;
                } else {
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (b[i].flag == 1) {
                    sum += max(b[i].y, b[i].z);
                }
            }
            max_ = max(max_, sum);
        } else if (f2 > n/2) {
            for (int i = 0; i < n; i++) {
                if (b[i].flag == 1 || b[i].flag == 3) {
                    sum += max(b[i].x, b[i].z);
                    b[i].flag = 0;
                    b[i].y = 0;
                }
            }
            sort(b, b + n, cmp_y);
            for (int i = 0; i < n; i++) {
                if (cnt <= n/2) {
                    sum += b[i].y;
                    b[i].flag = 0;
                    cnt++;
                } else {
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (b[i].flag == 2) {
                    sum += max(b[i].x, b[i].z);
                }
            }
            max_ = max(max_, sum);
        } else if (f3 > n/2) {
            for (int i = 0; i < n; i++) {
                if (b[i].flag == 1 || b[i].flag == 2) {
                    sum += max(b[i].x, b[i].y);
                    b[i].flag = 0;
                    b[i].z = 0;
                }
            }
            sort(b, b + n, cmp_z);
            for (int i = 0; i < n; i++) {
                if (cnt <= n/2) {
                    sum += b[i].z;
                    b[i].flag = 0;
                    cnt++;
                } else {
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (b[i].flag == 3) {
                    sum += max(b[i].x, b[i].y);
                }
            }
            max_ = max(max_, sum);
        }
        sort(b, b + n, cmp_x);
        sum = 0, cnt = 1, cnt_ = 0;
        for (int i = 0; i < n; i++) {
            if (cnt <= n / 2) {
                if (b[i].x < b[i].y || b[i].x < b[i].z) {
                    int c = max(b[n / 2 + cnt_].y, b[n / 2 + cnt_].z) - b[n / 2 + cnt_].x;
                    int d = max(b[i].y, b[i].z) - b[i].x;
                    if (d > c && (n / 2 + cnt_) < n) {
                        continue;
                        cnt_++;
                    } else {
                        sum += b[i].x;
                        cnt++;
                        b[i].x = 0;
                        b[i].y = 0;
                        b[i].z = 0;
                    }
                } else {
                    sum += b[i].x;
                    cnt++;
                    b[i].x = 0;
                    b[i].y = 0;
                    b[i].z = 0;
                }
            } else {
                break;
            }
        }
        for (int j = n / 2; j < n; j++) {
            sum += max(b[j].y, b[j].z);
        }
        max_ = max(max_, sum);
        for (int i = 0; i < n; i++) {
            b[i].x = a[i].x;
            b[i].y = a[i].y;
            b[i].z = a[i].z;
        }
        sort(b, b + n, cmp_y);
        sum = 0, cnt = 1, cnt_ = 0;
        for (int i = 0; i < n; i++) {
            if (cnt <= n / 2) {
                if (b[i].y < b[i].x || b[i].y < b[i].z) {
                    int c = max(b[n / 2 + cnt_].x, b[n / 2 + cnt_].z) - b[n / 2 + cnt_].y;
                    int d = max(b[i].x, b[i].z) - b[i].y;
                    if (d > c && (n / 2 + cnt_) < n) {
                        continue;
                        cnt_++;
                    } else {
                        sum += b[i].y;
                        cnt++;
                        b[i].x = 0;
                        b[i].y = 0;
                        b[i].z = 0;
                    }
                } else {
                    sum += b[i].y;
                    cnt++;
                    b[i].x = 0;
                    b[i].y = 0;
                    b[i].z = 0;
                }

            } else {
                break;
            }
        }
        for (int j = n / 2; j < n; j++) {
            sum += max(b[j].x, b[j].z);
        }
        max_ = max(max_, sum);
        sort(a, a + n, cmp_z);
        sum = 0, cnt = 1, cnt_ = 0;
        for (int i = 0; i < n; i++) {
            if (cnt <= n / 2) {
                if (b[i].z < b[i].y || b[i].z < b[i].x) {
                    int c = max(b[n / 2 + cnt_].y, b[n / 2 + cnt_].x) - b[n / 2 + cnt_].z;
                    int d = max(b[i].y, b[i].x) - b[i].z;
                    if (d > c && (n / 2 + cnt_) < n) {
                        continue;
                        cnt_++;
                    } else {
                        sum += b[i].z;
                        cnt++;
                        b[i].x = 0;
                        b[i].y = 0;
                        b[i].z = 0;
                    }
                } else {
                    sum += b[i].z;
                    cnt++;
                    b[i].x = 0;
                    b[i].y = 0;
                    b[i].z = 0;
                }
            } else {
                break;
            }
        }
        for (int j = n / 2; j < n; j++) {
            sum += max(b[j].y, b[j].x);
        }
        max_ = max(max_, sum);
        cout << max_ << endl;
    }
}
