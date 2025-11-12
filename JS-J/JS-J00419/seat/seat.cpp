#define MAXN 102
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, num, x, y;
int a[MAXN];
void init(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    num = n * m;
    for(int i = 0; i < num; ++ i)
        cin >> a[i];
    return;
}

bool cmp(int a, int b){
    return a > b;
}

void solve(){
    int t = a[0];
    sort(a, a + num, cmp);
    int p = 0;
    while(a[p] != t){
        ++ p;
    }
    x = p / n + 1;
    int k = p % n;
    if(x % 2 == 1){
        y = k + 1;
    }else{
        y = n - k;
    }
    cout << x << " " << y << endl;
    return;
}

void close(){
    fclose(stdin);
    fclose(stdout);
    return;
}

int main(){
    init();
    solve();
    close();
    return 0;
}
