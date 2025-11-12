#icnlude <bits/stdc++.h>
using namespace std;

int number[1000005];

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int a,b;
    int tol = 0;
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> number[i];
        tol = tol + number[i];
    }
    cout << (tol/2) + 1 <<endl;
    return 0;
}