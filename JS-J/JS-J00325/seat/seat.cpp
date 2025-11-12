#include<bits/stdc++.h>
using namespace std;
int a[10005] = {};
bool cmp(int a , int b){
    return a > b;
}
int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    int nn = n*m;
    for(int i = 1; i <= nn; i++){
        cin >> a[i];
    }
    int cnt = a[1];
    sort(a+1 , a+n*m+1 , cmp);
    int num = 0;
    for(int i = 1; i <= nn; i++){
        if(a[i] == cnt){
            num = i;
            break;
        }
    }
    cout << (num + m - 1) / m << " " << (num-1) % m +1;
    return 0;
}
