#include<bits/stdc++.h>
using namespace std;
int n,m,R;
const int maxn = 105;
int a[maxn];
static bool cmp1(int& x,int& y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    memset(a,0,sizeof(a));
    cin >> n >> m >> R;
    for(int i = 1;i<n*m;i++){
        cin >> a[i];
    }
    a[n*m] = R;
    sort(a+1,a+n*m+1,cmp1);
    int cnt = 1;
    for(int i = 1;i<=m;i++){
        if(i%2 == 1){
            for(int j = 1;j <= n;j++){
                if(a[cnt] == R){
                    cout << i << ' ' << j;
                }
                cnt++;
            }
        }
        else if(i%2 == 0){
            for(int j = n;j >= 1;j--){
                if(a[cnt] == R){
                    cout << i << ' ' << j;
                }
                cnt++;
            }
        }
    }
    return 0;
}
