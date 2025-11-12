#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
#define N 100001
using namespace std;
LL n,T,a[N][3],k,dt[N],x,ans,d[3][N],c,b[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--){
        k = 0;
        ans = 0;
        memset(b,0,sizeof(b));
        memset(d,0,sizeof(d));
        memset(dt,0,sizeof(dt));
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if(a[i][0] > a[i][1]){
                if(a[i][0] > a[i][2])x = 0;
                else x = 2;
            }
            else{
                if(a[i][2] > a[i][1])x = 2;
                else x = 1;
            }
            ans += a[i][x];
            d[x][b[x]++] = i;
            if(b[x] > n / 2){
                c = x;
            }
        }
        for(int i = 0;i < b[c];i++){
            x = d[c][i];
            dt[i] = a[x][c] - max(a[x][c % 3 + 1],a[x][(c + 1) % 3 + 1]);
        }
        sort(dt,dt + b[c]);
        while(b[c] > n / 2){
            if(dt[k] >= 0){
                ans -= dt[k];
                b[c]--;
            }
            k++;
        }
        cout << ans << endl;
    }
    return 0;
}