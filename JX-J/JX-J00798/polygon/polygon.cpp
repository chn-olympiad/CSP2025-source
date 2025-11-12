#include<bits/stdc++.h>
using namespace std;
int a[5005],n,cnt;
bool pd(int l, int a[]) {
    if (l < 3) return false;
    int sum = 0, maxn = 0;
    for (int i = 1; i <= l; i++) {
        sum += a[i];
        maxn = max(maxn,a[i]);
    }
    if (sum <= maxn*2) return false;
    return true;
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            for (int k = j+1; k <= n; k++) {
                int b[5] = {0,a[i],a[j],a[k]};
                if (pd(3,b) == 1)
                    cnt++;
            }
        }
    }
    for (int q = 1; q <= n; q++) {
        for (int i = q+1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                for (int k = j+1; k <= n; k++) {
                    int b[6] = {0,a[q],a[i],a[j],a[k]};
                    if (pd(4,b) == 1)
                        cnt++;
                }
            }
        }
    }
    for (int w = 1; w <= n; w++) {
        for (int q = w+1; q <= n; q++) {
            for (int i = q+1; i <= n; i++) {
                for (int j = i+1; j <= n; j++) {
                    for (int k = j+1; k <= n; k++) {
                        int b[7] = {0,a[w],a[q],a[i],a[j],a[k]};
                        if (pd(5,b) == 1)
                            cnt++;
                    }
                }
            }
        }
    }
    for (int e = 1; e <= n; e++) {
        for (int w = e+1; w <= n; w++) {
            for (int q = w+1; q <= n; q++) {
                for (int i = q+1; i <= n; i++) {
                    for (int j = i+1; j <= n; j++) {
                        for (int k = j+1; k <= n; k++) {
                            int b[118] = {0,a[e],a[w],a[q],a[i],a[j],a[k]};
                            if (pd(6,b) == 1)
                                cnt++;
                        }
                    }
                }
            }
        }
    }
    for (int r = 1; r <= n; r++) {
        for (int e = r+1; e <= n; e++) {
            for (int w = e+1; w <= n; w++) {
                for (int q = w+1; q <= n; q++) {
                    for (int i = q+1; i <= n; i++) {
                        for (int j = i+1; j <= n; j++) {
                            for (int k = j+1; k <= n; k++) {
                                int b[118] = {0,a[r],a[e],a[w],a[q],a[i],a[j],a[k]};
                                if (pd(7,b) == 1)
                                    cnt++;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int t = 1; t <= n; t++) {
        for (int r = t+1; r <= n; r++) {
            for (int e = r+1; e <= n; e++) {
                for (int w = e+1; w <= n; w++) {
                    for (int q = w+1; q <= n; q++) {
                        for (int i = q+1; i <= n; i++) {
                            for (int j = i+1; j <= n; j++) {
                                for (int k = j+1; k <= n; k++) {
                                    int b[118] = {0,a[t],a[r],a[e],a[w],a[q],a[i],a[j],a[k]};
                                    if (pd(8,b) == 1)
                                        cnt++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int y = 1; y <= n; y++) {
        for (int t = y+1; t <= n; t++) {
            for (int r = t+1; r <= n; r++) {
                for (int e = r+1; e <= n; e++) {
                    for (int w = e+1; w <= n; w++) {
                        for (int q = w+1; q <= n; q++) {
                            for (int i = q+1; i <= n; i++) {
                                for (int j = i+1; j <= n; j++) {
                                    for (int k = j+1; k <= n; k++) {
                                        int b[118] = {0,a[y],a[t],a[r],a[e],a[w],a[q],a[i],a[j],a[k]};
                                        if (pd(9,b) == 1)
                                            cnt++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        for (int y = u+1; y <= n; y++) {
            for (int t = y+1; t <= n; t++) {
                for (int r = t+1; r <= n; r++) {
                    for (int e = r+1; e <= n; e++) {
                        for (int w = e+1; w <= n; w++) {
                            for (int q = w+1; q <= n; q++) {
                                for (int i = q+1; i <= n; i++) {
                                    for (int j = i+1; j <= n; j++) {
                                        for (int k = j+1; k <= n; k++) {
                                            int b[118] = {0,a[u],a[y],a[t],a[r],a[e],a[w],a[q],a[i],a[j],a[k]};
                                            if (pd(10,b) == 1)
                                                cnt++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int o = 1; o <= n; o++) {
        for (int u = o+1; u <= n; u++) {
            for (int y = u+1; y <= n; y++) {
                for (int t = y+1; t <= n; t++) {
                    for (int r = t+1; r <= n; r++) {
                        for (int e = r+1; e <= n; e++) {
                            for (int w = e+1; w <= n; w++) {
                                for (int q = w+1; q <= n; q++) {
                                    for (int i = q+1; i <= n; i++) {
                                        for (int j = i+1; j <= n; j++) {
                                            for (int k = j+1; k <= n; k++) {
                                                int b[118] = {0,a[o],a[u],a[y],a[t],a[r],a[e],a[w],a[q],a[i],a[j],a[k]};
                                                if (pd(11,b) == 1)
                                                    cnt++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
