#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e2+10;
int n, m, a[N], s[N][N], x, idx;
bool cmp(int a, int b){
    return a>b;
}
signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++) cin >> a[i];
    x=a[1];
    sort(a+1, a+1+n*m, cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            s[j][i]=a[++idx];
            if(s[j][i]==x){
                cout << i << ' ' << j;
                return 0;
            }
        }
        i++;
        if(i>m) break;
        for(int j=n;j>=1;j--){
            s[j][i]=a[++idx];
            if(s[j][i]==x){
                cout << i << ' ' << j;
                return 0;
            }
        }
    }
    return 0;
}
