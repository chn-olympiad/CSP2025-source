#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int n,m;
pair <int,int> a[N * N + 5];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1,a + 1 + n * m,greater <pair <int,int> >());
    int id = 0;
    for(int i = 1;i <= n * m;i++){
        if(a[i].second == 1)
            id = i;
    }
    int row = 0,col = 0;
    row = id % (2 * n);
    col = ceil(id * 1.0 / n);
    if(id % (2 * n) > n){
        row = 2 * n - row + 1;
    }
    cout << col  << " " << row << endl;
    return 0;
}