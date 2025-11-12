#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
int n,m,a[N + 5],rp,com,ans_n,ans_m;//rp = "R's point",com = "R's rank"
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++)
        cin >> a[i];
    rp = a[1];
    sort(a + 1,a + 1 + n * m,greater<int>());
    /*for(int i = 1;i <= n * m;i++)
        cout << a[i] << ' ';*/
    for(int i = 1;i <= n * m;i++){
        if(a[i] == rp){
            com = i;
            break;
        }
    }
    //cout << "com = " << com << endl;
    ans_m = (com + n - 1) / n;
    if(ans_m % 2)
        ans_n = (com - 1) % n + 1;
    else
        ans_n = n + 1 -((com - 1) % n + 1);
    cout << ans_m << ' ' << ans_n << '\n';
    return 0;
}
