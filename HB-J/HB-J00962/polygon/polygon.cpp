#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005],cnt = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    if(n == 3){
        if(a[1] + a[2] + a[3] > 2 * a[3]){
            cnt++;
        }
    }
    if(n == 4){
        if(a[1] + a[2] + a[3] + a[4] > 2 * a[4]){
            cnt++;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    int i1,j1,k1;
                    if(i == j || j == k || i == k || j == i1 || k == i1 || i == j1 || k == j1 || i == k1 || j == k1){
                        continue;
                    }
                    if(a[i] + a[j] + a[k] > 2 * a[max({i,j,k})]){
                        cnt++;
                        i1 = i,j1 = j,k1 = k;
                    }
                }
            }
        }
    }
    if(n == 5){
        if(a[1] + a[2] + a[3] + a[4] + a[5] > 2 * a[5]){
            cnt++;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    int i1,j1,k1;
                    if(i == j || j == k || i == k || j == i1 || k == i1 || i == j1 || k == j1 || i == k1 || j == k1){
                        continue;
                    }
                    if(a[i] + a[j] + a[k] > 2 * a[max({i,j,k})]){
                        cnt++;
                        i1 = i,j1 = j,k1 = k;
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    for(int l = 1;l <= n;l++){
                        int i1,j1,k1,l1;
                        if(i == j || i == k || i == l || j == k || j == l || k == l || i == j1 || i == k1 || i == l1 || j == i1 || j == k1 || j == l1 || k == i1 || k == j1 || k == l1 || l == i1 || l == j1 || l == k1){
                            continue;
                        }
                        if(a[i] + a[j] + a[k] + a[l] > 2 * a[max({i,j,k,l})]){
                            cnt++;
                            i1 = i,j1 = j,k1 = k,l1 = l;
                        }
                    }
                }
            }
        }
    }
    if(n == 6){
        if(a[1] + a[2] + a[3] + a[4] + a[5] + a[6] > 2 * a[6]){
            cnt++;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    int i1,j1,k1;
                    if(i == j || j == k || i == k || j == i1 || k == i1 || i == j1 || k == j1 || i == k1 || j == k1){
                        continue;
                    }
                    if(a[i] + a[j] + a[k] > 2 * a[max({i,j,k})]){
                        cnt++;
                        i1 = i,j1 = j,k1 = k;
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    for(int l = 1;l <= n;l++){
                        int i1,j1,k1,l1;
                        if(i == j || i == k || i == l || j == k || j == l || k == l || i == j1 || i == k1 || i == l1 || j == i1 || j == k1 || j == l1 || k == i1 || k == j1 || k == l1 || l == i1 || l == j1 || l == k1){
                            continue;
                        }
                        if(a[i] + a[j] + a[k] + a[l] > 2 * a[max({i,j,k,l})]){
                            cnt++;
                            i1 = i,j1 = j,k1 = k,l1 = l;
                        }
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    for(int l = 1;l <= n;l++){
                        for(int m = 1;m <= n;m++){
                            int i1,j1,k1,l1,m1;
                            if(i == j || i == k || i == l || i == m || j == k || j == l || j == m|| k == l || k == m || l == m || i == j1 || i == k1 || i == l1 || i == m1 || j == i1 || j == k1 || j == l1 || j == m1 || k == i1 || k == j1 || k == l1 || k == m1 || l == i1 || l == j1 || l == k1 || l == m1 || m == i1 || m == j1 || m == k1 || m == l1){
                                continue;
                            }
                            if(a[i] + a[j] + a[k] + a[l] + a[m] > 2 * a[max({i,j,k,l,m})]){
                                cnt++;
                                i1 = i,j1 = j,k1 = k,l1 = l,m1 = m;
                            }
                        }
                    }
                }
            }
        }
    }
    if(n == 7){
        if(a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] > 2 * a[7]){
            cnt++;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    int i1,j1,k1;
                    if(i == j || j == k || i == k || j == i1 || k == i1 || i == j1 || k == j1 || i == k1 || j == k1){
                        continue;
                    }
                    if(a[i] + a[j] + a[k] > 2 * a[max({i,j,k})]){
                        cnt++;
                        i1 = i,j1 = j,k1 = k;
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    for(int l = 1;l <= n;l++){
                        int i1,j1,k1,l1;
                        if(i == j || i == k || i == l || j == k || j == l || k == l || i == j1 || i == k1 || i == l1 || j == i1 || j == k1 || j == l1 || k == i1 || k == j1 || k == l1 || l == i1 || l == j1 || l == k1){
                            continue;
                        }
                        if(a[i] + a[j] + a[k] + a[l] > 2 * a[max({i,j,k,l})]){
                            cnt++;
                            i1 = i,j1 = j,k1 = k,l1 = l;
                        }
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    for(int l = 1;l <= n;l++){
                        for(int m = 1;m <= n;m++){
                            int i1,j1,k1,l1,m1;
                            if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m || i == j1 || i == k1 || i == l1 || i == m1 || j == i1 || j == k1 || j == l1 || j == m1 || k == i1 || k == j1 || k == l1 || k == m1 || l == i1 || l == j1 || l == k1 || l == m1 || m == i1 || m == j1 || m == k1 || m == l1){
                                continue;
                            }
                            if(a[i] + a[j] + a[k] + a[l] + a[m] > 2 * a[max({i,j,k,l,m})]){
                                cnt++;
                                i1 = i,j1 = j,k1 = k,l1 = l,m1 = m;
                            }
                        }
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    for(int l = 1;l <= n;l++){
                        for(int m = 1;m <= n;m++){
                            for(int p = 1;p <= n;p++){
                                int i1,j1,k1,l1,m1,p1;
                                if(i == j || i == k || i == l || i == m || i == p || j == k || j == l || j == m || j == p || k == l || k == m || k == p || l == m || l == p || m == p || i == j1 || i == k1 || i == l1 || i == m1 || i == p1 || j == i1 || j == k1 || j == l1 || j == m1 || j == p1 || k == i1 || k == j1 || k == l1 || k == m1 || k == p1 || l == i1 || l == j1 || l == k1 || l == m1 || l == p1 || m == i1 || m == j1 || m == k1 || m == l1 || m == p1 || p == i1 || p == j1 || p == k1 || p == l1 || p == m1){
                                    continue;
                                }
                                if(a[i] + a[j] + a[k] + a[l] + a[m] + a[p] > 2 * a[max({i,j,k,l,m,p})]){
                                    cnt++;
                                    i1 = i,j1 = j,k1 = k,l1 = l,m1 = m,p1 = p;
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
