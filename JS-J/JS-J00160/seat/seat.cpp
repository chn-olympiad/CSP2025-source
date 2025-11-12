#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 110;
int n,m,a[MAXN];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++) cin >> a[i];
    int ms = a[1],p;
    sort(a + 1,a + n * m + 1,greater<int>());
    for(int i = 1;i <= n * m;i++){
        //cout << a[i] << endl;
        if(a[i] == ms){
            p = i;
            break;
        }
    }
    int c = (p - 1) / n + 1,r;
    if(c % 2){
        r = (p - 1) % n + 1;
    }else{
        r = n - (p - 1) % n;
    }
    cout << c << " " << r << endl;
    return 0;
}
