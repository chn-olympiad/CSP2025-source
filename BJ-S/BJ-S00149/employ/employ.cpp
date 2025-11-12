#include <bits/stdc++.h>
using namespace std;
int n,m;
char c;
int p;
bool lev[505];
int pat[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    p=0;
    memset(lev,0,sizeof(lev));
    for (int i=0;i<n;i++){
        cin >> c;
        if (c == '1'){
            lev[i] = 1;
        }
    }
    for (int i=0;i<n;i++){
        cin >> pat[i];
        if (pat[i] == 0){
            p++;
        }
    }
    for (int i=0;i<n;i++){
        if (n == m&pat[i] == 0){
            cout << 0 << endl;
        }
        if (n == m&lev[i] == 0){
            cout << 0 << endl;
        }
    }
    if (m == n){
        long long w=1;
        for (int j=1;j<=n;j++){
            w *=j;
            w %=998244353;
        }
        cout << w << endl;
        return 0;
    }
    if (m == 1){
        bool f;
        int w=0;
        int k=0;
        int lis[500][2];
        memset(lis,0,sizeof(lis));
        int l=0;
        for (int i=0;i<n;i++){
            if (lev[i]){
                lis[l][0] = i;
                l++;
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<l;j++){
                if (pat[i]>lis[j][0]){
                    lis[j][1]++;
                }
                else{
                    break;
                }
            }
        }
        f = 1;
        for (int i=0;i<l;i++){
            k = lis[i][1];
            if (!f){
                break;
            }
            for (int j=0;j<i;j++){
                if (n<=lis[j][1]+j){
                    k=0;
                    f = 0;
                    break;
                }
                k *= (n-lis[j][1]-j);
                k %= 998244353;
            }
            for (int j=0;j<n-i-1;j++){
                k *= j+1;
                k %= 998244353;
            }
            w += k;
        }
        cout << w << endl;
        return 0;
    }
    if (p+m>n){
        cout << 0 << endl;
    }
    return 0;
}