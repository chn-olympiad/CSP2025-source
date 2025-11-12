#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int m;
    int x = 0;
    int y = 0;
    int z = 0;
    cin >> n >> m;
    string txt;
    int s[n];
    int c[n];
    cin >> txt;
    int l = txt.length();
    for(int i = 0; i < l; ++i) {
        s[i] = txt[i] - '0';
        if(s[i] == 0) {
            x = 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
        if(c[i] == 0) {
            z = 1;
        }
    }
    if(n == m && (x == 1 || z == 1)) {
        cout << "0";
        return 0;
    } else if(n == m){
        long long ans = 1;
        for(int i = 1; i <= n; ++i) {
            ans = ans * i;
            ans = ans % 998244353;
        }
        cout << ans;
        return 0;
    }
    if(x == 0) {
        long long ans = 1;
        for(int i = 1; i <= n; ++i) {
            ans = ans * i;
            ans = ans % 998244353;
        }
        cout << ans;
        return 0;
    }
    if(n <= 10) {
        int num[10];
        int x = 0;
        int f = 0;
        int ans = 0;
        for(int i = 0; i < 10; ++i) {
            num[i] = 0;
        }
        for(int q = 0; q < n; ++q) {
            if(num[q] == 0) {
                num[q] = 1;
                if(s[q] == 1 && c[q] - f > 0) {
                    ++x;
                } else {
                    ++f;
                }
            }
            for(int w = 0; w < n; ++w) {
                if(num[w] == 0) {
                    num[w] = 1;
                    if(s[w] == 1 && c[w] - f > 0) {
                        ++x;
                    } else {
                        ++f;
                    }
                }
                for(int e = 0; e < n; ++e) {
                    if(num[e] == 0) {
                        num[e] = 1;
                        if(s[e] == 1 && c[e] - f > 0) {
                            ++x;
                        } else {
                            ++f;
                        }
                    }
                    for(int r = 0; r < n; ++r) {
                        if(num[r] == 0) {
                            num[r] = 1;
                            if(s[r] == 1 && c[r] - f > 0) {
                                ++x;
                            } else {
                                ++f;
                            }
                        }
                        for(int t = 0; t < n; ++t) {
                            if(num[t] == 0) {
                                num[t] = 1;
                                if(s[t] == 1 && c[t] - f > 0) {
                                    ++x;
                                } else {
                                    ++f;
                                }
                            }
                            for(int y = 0; y < n; ++y) {
                                if(num[y] == 0) {
                                    num[y] = 1;
                                    if(s[y] == 1 && c[y] - f > 0) {
                                        ++x;
                                    } else {
                                        ++f;
                                    }
                                }
                                for(int u = 0; u < n; ++u) {
                                    if(num[u] == 0) {
                                        num[u] = 1;
                                        if(s[u] == 1 && c[u] - f > 0) {
                                            ++x;
                                        } else {
                                            ++f;
                                        }
                                    }
                                    for(int i = 0; i < n; ++i) {
                                        if(num[i] == 0) {
                                            num[i] = 1;
                                            if(s[i] == 1 && c[i] - f > 0) {
                                                ++x;
                                            } else {
                                                ++f;
                                            }
                                        }
                                        for(int o = 0; o < n; ++o) {
                                            if(num[o] == 0) {
                                                num[o] = 1;
                                                if(s[o] == 1 && c[o] - f > 0) {
                                                    ++x;
                                                } else {
                                                    ++f;
                                                }
                                            }
                                            for(int p = 0; p < n; ++p) {
                                                if(num[p] == 0) {
                                                    num[p] = 1;
                                                    if(s[p] == 1 && c[p] - f > 0) {
                                                        ++x;
                                                    } else {
                                                        ++f;
                                                    }
                                                }
                                                num[p] = 0;
                                            }
                                            num[o] = 0; 
                                        }
                                        num[i] = 0;
                                    }
                                    num[u] = 0;
                                }
                                num[y] = 0;
                            }
                            num[t] = 0;
                        }
                        num[r] = 0;
                    }
                    num[e] = 0;
                }
                num[w] = 0;
            }
            num[q] = 0;
            if(x >= m) {
                ++ans;
                ans = ans % 998244353; 
            }
            x = 0;
            f = 0;
        }
        cout << ans;
        return 0;
    }
    return 0;
}