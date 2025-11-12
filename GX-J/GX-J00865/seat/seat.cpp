#include<bits/stdc++.h>
using namespace std;
const int maxn = 114;
int a[maxn];
int b[15][15];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int r = a[1];
    sort(a+1, a+n*m+1, cmp);
    int p = 1;
    for(int i=1;i<=m;i++){
        if(i % 2 == 1){
            for(int j=1;j<=n;j++){
                b[j][i] = a[p];
                if(b[j][i] == r){
                    cout<<i<<' '<<j;
                    return 0;
                }
                p++;
            }
        }
        else if(i % 2 == 0){
            for(int j=n;j>=1;j--){
                b[j][i] = a[p];
                if(b[j][i] == r){
                    cout<<i<<' '<<j;
                    return 0;
                }
                p++;
            }
        }
    }

    return 0;
}
