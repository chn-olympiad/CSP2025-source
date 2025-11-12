# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;

int n, t, s1n, s2n, s3n;
long long s1, s2, s3;

struct People {
    int cs[4];
    int mac;
    int tmac;
    int mic;
} arr[100005];

int erFen(int mac, int fc) {
    int l=1, r=n, ans=-1;
    while (l <= r) {
        int mid = (l + r) / 2, x=-1;
        if (fc == 3) {
            x = arr[mid].cs[3];
        } else if (fc == 2) {
            x = arr[mid].cs[2];
        } else {
            x = arr[mid].cs[1];
        }
        if (x == mac) {
            ans = mid;
            r = mid - 1;
        } else if (x > mac) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

bool cmpS(const People &x, const People &y) {
    if (x.mac == y.mac) {
        return x.cs[x.mac] > y.cs[y.mac];
    }
    return x.mac < y.mac;
}

bool cmpS2(const People &x, const People &y) {
    if (x.tmac == y.tmac) {
        return x.cs[x.tmac] > y.cs[y.tmac];
    }
    return x.tmac < y.tmac;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for (int r=0; r<t; r++) {
        cin >> n;
        int tn = n;
        for (int i=1; i<=n; i++) {
            cin >> arr[i].cs[1] >> arr[i].cs[2] >> arr[i].cs[3];
            if (arr[i].cs[1] > arr[i].cs[2]) {
                if (arr[i].cs[3] > arr[1].cs[2]) {
                    arr[i].mac = 3;
                    arr[i].tmac = 1;
                    arr[i].mic = 2;
                } else {
                    arr[i].mac = 1;
                    if (arr[i].cs[2] > arr[i].cs[3]) {
                        arr[i].tmac = 2;
                        arr[i].mic = 3;
                    } else {
                        arr[i].mic = 2;
                        arr[i].tmac = 3;
                    }
                }
            } else {
                if (arr[i].cs[3] > arr[i].cs[2]) {
                    arr[i].mac = 3;
                    arr[i].tmac = 2;
                    arr[i].mic = 1;
                } else {
                    arr[i].mac = 2;
                    if (arr[i].cs[3] > arr[i].cs[1]) {
                        arr[i].tmac = 2;
                        arr[i].mic = 1;
                    } else {
                        arr[i].mic = 2;
                        arr[i].tmac = 1;
                    }
                }
            }
        }
        sort(arr+1, arr+n+1, cmpS);
        int s2s=erFen(2, 3), s3s=erFen(3, 3);
        if (s3s != -1) {
            while (n && s3n <= tn / 2 && n >= s3s) {
                s3 += arr[n].cs[3];
                s3n++;
                n--;
            }
        }
        if (s2s != -1) {
            int t = s3s-1;
            while (n && s2n <= tn / 2 && n >= s2s) {
                s2 += arr[t].cs[2];
                s2n++;
                swap(arr[t], arr[n]);
                n--;
            }
        }
        if (arr[1].mac != 1) {
            int t = s2s-1;
            while (n && s1n <= tn / 2 && n >= 1) {
                s1 += arr[t].cs[1];
                s1n++;
                swap(arr[t], arr[n]);
                n--;
            }
        }
        if (n > 0) {
            sort(arr+1, arr+n+1, cmpS2);
            int s2s=erFen(2, 2), s3s=erFen(3, 2);
            if (s3s != -1) {
                while (n && s3n <= tn / 2 && n >= s3s) {
                    s3 += arr[n].cs[3];
                    s3n++;
                    n--;
                }
            }
            if (s2s != -1) {
                int t = s3s-1;
                while (n && s2n <= tn / 2 && n >= s2s) {
                    s2 += arr[t].cs[2];
                    s2n++;
                    swap(arr[t], arr[n]);
                    n--;
                }
            }
            if (arr[1].mac != 1) {
                int t = s2s-1;
                while (n && s1n <= tn / 2 && n >= 1) {
                    s1 += arr[t].cs[1];
                    s1n++;
                    swap(arr[t], arr[n]);
                    n--;
                }
            }
            if (n > 0) {
                for (int i=1; i<=n; i++) {
                    if (arr[i].mic == 1) {
                        s1 += arr[i].cs[1];
                    } else if (arr[i].mic == 2) {
                        s2 += arr[i].cs[2];
                    } else {
                        s3 += arr[i].cs[3];
                    }
                }
            }
        }
        cout << s1 + s2 + s3 << endl;
    }
    return 0;
}
