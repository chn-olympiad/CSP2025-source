#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x > y;
}

int n,m,r;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
    }
    r = a[1];
    int num;
    sort(a + 1,a + 1 + n * m,cmp);
    for(int i = 1;i <= n * m;i++){
        if(a[i] == r){
            num = i;
            break;
        }
    }
    if(m % 2 == 1){
        if(num > n * (m - 1)){
            num -= n * (m - 1);
            cout << m << " " << num;
            return 0;
        }
        m--;
    }
    int sum = num / (2 * n) + 1;
    num = num % (2 * n);
    if(num == 0){
        num = 2 * n;
    }
    if(num <= n){
        cout << 2 * sum - 1 << " " << num;
    }
    else{
        cout << 2 * sum << " " <<  (2 * n - num + 1);
    }

    return 0;
}
