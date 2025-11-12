#include <bits/stdc++.h>
using namespace std;

int n;
int a[5010] = {};
long long cnt = 0;
long long sum = 0;
int d = 1;

void dfs(int i){

    d ++;
    for (int j = i + 1; j < n; j++){
        sum += a[j];

        if (sum > 2 * a[j]&& d >= 3){
            cnt+=n-j;
            sum -=a[j];
        }
        else{
            dfs(j);
            sum -=a[j];
        }
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    dfs(-1);
    cout << cnt;
    return 0;
}
