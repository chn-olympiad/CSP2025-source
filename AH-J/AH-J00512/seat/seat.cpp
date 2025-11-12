#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e2 + 10;
struct st{
    int s, num;
}a[N];
bool cmp(st n1, st n2){
    return n1.s > n2.s;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>a[i].s;
        a[i].num = i;
    }
    sort(a + 1, a + n * m + 1, cmp);
    int i = 1, j = 1, pos = 1;
    while(true){
        if(a[pos].num == 1){
            cout<<j<<" "<<i;
            return 0;
        }
        if(j % 2 == 1){
            if(i == n){
                j++;
            }else{
                i++;
            }
        }else{
            if(i == 1){
                j++;
            }else{
                i--;
            }
        }
        pos++;
    }
    return 0;
}
