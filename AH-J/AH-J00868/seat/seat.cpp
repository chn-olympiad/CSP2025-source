#include<bits/stdc++.h>
using namespace std;
const int N = 201;
int a[N];
bool cmp(int x, int y){
    return x > y;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    int stu = a[1], num;
    sort(a + 1, a + n*m + 1, cmp);
    for(int i = 1; i <= n*m; i++){
        if(a[i] == stu) num = i;
    }
    int dx, dy;
    if(num % n == 0) dy = num / n;
    else dy = num / n + 1;
    if(dy % 2 == 1){
        if(num % n != 0) dx = num % n;
        else dx = n;
    }else{
        if(num % n == 0) dx = 1;
        else dx = n - num % n + 1;
    }
    cout << dy << " " << dx;
    return 0;
}
