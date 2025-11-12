#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 110;
int mp[N][N];
int a[N * N];
int s[N][N];
bool cmp(int a,int b){
    return a > b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;

    for(int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
    }
    int aims = a[1];
    sort(a + 1,a + 1 + n * m,cmp);
    int cnt = 1;
    for(int i = 1;i <= m;i++){
        if(i % 2 == 1){
            for(int j = 1;j <= n;j++){
                s[i][j] = a[cnt];
                if(s[i][j] == aims){
                    cout << i << ' ' << j << "\n";
                    return 0;
                }
                cnt++;
            }
        }
        else{
            for(int j = n;j >= 1;j--){
                s[i][j] = a[cnt];
                if(s[i][j] == aims){
                    cout << i << ' ' << j << "\n";
                    return 0;
                }
                cnt++;
            }
        }
    }
    return 0;
}
