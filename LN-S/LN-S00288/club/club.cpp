#include <bits/stdc++.h>
const int MAXN = (1e5+7);
const int MAXM = (2e4+7);
using namespace std;

namespace L1SkyL {
    void Main();
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    L1SkyL::Main();
    return 0;
}

namespace L1SkyL{
    int t,n,cs,ans,suma,sumb;
    vector <int> ca,cb,delta;
    int a[MAXN],b[MAXN],c[MAXN];
    int cse[MAXN];
    bool cmp(int a,int b){
        return a > b;
    }
    bool cmp2(int a,int b){
        return a < b;
    }
    void dfs(int csa,int csb,int csc,int i,int sum){
        if (i == n + 1){
            ans = max(ans,sum);
            return;
        }
        if (csa < n / 2) dfs(csa + 1,csb,csc,i + 1,sum + a[i]);
        if (csb < n / 2) dfs(csa,csb + 1,csc,i + 1,sum + b[i]);
        if (csc < n / 2) dfs(csa,csb,csc + 1,i + 1,sum + c[i]);
    }
    void dfs2(int csa,int csb,int i,int sum){
        if (csa == n / 2 && csb == n / 2){
            ans = max(ans,sum);
            return;
        }
        if (csa < n / 2) dfs2(csa + 1,csb,i + 1,sum + a[i]);
        if (csb < n / 2) dfs2(csa,csb + 1,i + 1,sum + b[i]);
    }
    void Main(){
        iostream::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> t;
        while (t--){
            cin >> n;
            ans = 0;
            if (n <= 10){
                ans = 0;
                for (int i = 1;i <= n;++i){
                    cin >> a[i] >> b[i] >> c[i];
                }
                dfs(0,0,0,1,0);
                cout << ans << "\n";
                continue;
            } else {
                int flag = 1;
                int flag2 = 1;
                for (int i = 1;i <= n;++i){
                    cin >> a[i] >> b[i] >> c[i];
                    if (b[i] || c[i]) flag = 0;
                    if (c[i]) flag2 = 0;
                }
                if (flag){
                    sort(a + 1,a + 1 + n,cmp);
                    for (int i = 1;i <= n/2;++i){
                        ans += a[i];
                    }
                    cout << ans << "\n";
                    continue;
                } else if (!flag && flag2){
                    ca.clear(),cb.clear(),delta.clear();
                    suma = sumb = 0;
                    ans = 0;
                    for (int i = 1;i <= n;++i){
                        if (a[i] > b[i]) ++suma,ans += a[i],ca.push_back(i);
                        else ++sumb,ans += b[i],cb.push_back(i);
                    }
                    if (suma == sumb){
                        cout << ans << "\n";
                        continue;
                    } else {
                        if (suma > sumb){
                            for (int i : ca){
                                delta.push_back(a[i] - b[i]);
                            }
                            sort(delta.begin(),delta.end(),cmp2);
                            for (int i = 0;i < (suma - sumb) / 2;++i){
                                ans -= delta[i];
                            }
                            cout << ans << "\n";
                        } else {
                            for (int i : cb){
                                delta.push_back(b[i] - a[i]);
                            }
                            sort(delta.begin(),delta.end(),cmp2);
                            for (int i = 0;i < (sumb - suma) / 2;++i){
                                ans -= delta[i];
                            }
                            cout << ans << "\n";
                        }
                    }
                }
            }
            for (int i = 1;i <= n;++i) a[i] = b[i] = c[i] = 0;
        }
    }
}