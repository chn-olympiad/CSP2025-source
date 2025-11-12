#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node{
    int id;
    int w;
}a[105];
bool cmp(node A, node B){
    return A.w > B.w;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i].w;
        a[i].id = i;
    }
    sort(a + 1, a + n * m + 1, cmp);
    int cnt = 0, js = 1;
    bool flag = false;
    for(int i = 1;i <= n * m;i++){
        cnt++;
        if(cnt > n){
            cnt -= n;
            flag = !flag;
            js++;
        }
        if(a[i].id == 1){
            if(flag) cnt = n - cnt + 1;
            cout << js << " " << cnt;
            break;
        }
    }
    return 0;
}
