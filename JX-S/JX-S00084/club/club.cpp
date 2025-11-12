#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> x;
int maxn = -1;

int ar=0, br=0, cr=0;
void dfs(int n, int p, vector<int> a, vector<int> b, vector<int> c){
    if (p == n){
        int sum=0;
        for (int i=0; i < n; ++i){
            sum += x[i];
        }
        maxn = max(maxn, sum);
        return ;
    }

    if (ar+1 <= n/2){
        x[p]=a[p];
        ar++;
        dfs(n, p+1, a, b, c);
        ar--;
        x[p]=0;
    }

    if (br+1 <= n/2){
        x[p]=b[p];
        br++;
        dfs(n, p+1, a, b, c);
        br--;
        x[p]=0;
    }
    if (cr+1 <= n/2){
        x[p]=c[p];
        cr++;
        dfs(n, p+1, a, b, c);
        cr--;
        x[p]=0;
    }
}

void dfs2(int n, int p, vector<int> a, vector<int> b, vector<int> c){
    if (p == n){
        int sum=0;
        for (int i=0; i < n; ++i){
            sum += x[i];
        }
        maxn = max(maxn, sum);
        return ;
    }

    if (ar+1 <= n/2){
        x[p]=a[p];
        ar++;
        dfs(n, p+1, a, b, c);
        ar--;
        x[p]=0;
    }

    if (br+1 <= n/2){
        x[p]=b[p];
        br++;
        dfs(n, p+1, a, b, c);
        br--;
        x[p]=0;
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;

    while (t--){
        maxn=-1;
        int n;
        cin >> n;

        if (n > 8){ // c12
            vector<int> d(n);
            for (int i=0; i < n; ++i){
                int a, b, c;
                cin >> d[i] >> b >> c;
            }

            sort(d.begin(), d.end());
            int sum=0;
            for (int i=n-1; i >= n/2; --i){
                sum += d[i];
            }

            cout << sum << endl;
        }else if (n < 8){
            vector<int> a(n), b(n), c(n);
            for (int i=0; i < n; ++i){
                cin >> a[i] >> b[i] >> c[i];
            }

            x.resize(n, 0);
            dfs(n, 0, a, b, c);
            cout << maxn << endl;
        }
    }
}
