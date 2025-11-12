#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define endl "\n"
int n , m , ans;
struct node {
    int num , sum;
    bool operator < (const node &T) const{
        return sum > T.sum;
    }
} a[100010];
int main(){
    IOS
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n * m ; i ++ ) {
        cin >> a[i].sum;
        a[i].num = i;
    }
    sort (a + 1 , a + 1 + n * m);
    for (int i = 1 ; i <= n * m ; i ++ )
        if (a[i].num == 1) {
            ans = i;
            break;
        }
    int x = ans / n + (ans % n !=0 ? 1 : 0) , y;
    if (x % 2) y = (ans - 1) % n + 1;
    else y = n - ((ans - 1) % n + 1) + 1;
    cout << x << " " << y;
    return 0;
}
