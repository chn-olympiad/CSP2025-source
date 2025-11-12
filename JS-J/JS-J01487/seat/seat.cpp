#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[105],mp[15][15];
int r;
int ans_i,ans_j;
int cnt;

bool cmp(int a,int b){return a > b;}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i =1;i <= n * m;i++) cin >> a[i];
    r = a[1];
    sort(a + 1,a + 1 + n * m,cmp);
    for (int i = 1;i <= n;i++){
        if (i % 2){
            for (int j = 1;j <= m;j++){
                mp[i][j] = a[++cnt];
                if (a[cnt] == r) ans_i = i,ans_j = j;
            }
        }else{
            for (int j = m;j >= 1;j--){
                mp[i][j] = a[++cnt];
                if (a[cnt] == r) ans_i = i,ans_j = j;
            }
        }

    }
    cout << ans_i << " " << ans_j;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
