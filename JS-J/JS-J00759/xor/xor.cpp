#include<bits/stdc++.h>
using namespace std;
long long n , k , a[500001] , cnt = 0;
stack<long long> x;
void dfs(int xorn , int dis , int i){
    if(xorn == k && i == n){
        cnt = dis + 1;
        return;
    }else if(xorn == k){
        x.push(xorn);
        dfs(a[i + 1] , dis + 1 , i + 1);
    }else if(i == n){
        if(x.empty()){
            return;
        }
        dfs(x.top() ^ xorn , dis + 1 , i);
        x.pop();
    }else dfs(xorn ^ a[i + 1] , dis , i + 1);
}
int main(){
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
    }
    dfs(a[1] , 0 , 1);
    cout << cnt;
    return 0;
}
