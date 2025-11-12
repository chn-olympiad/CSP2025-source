#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e5 + 5;
const int M = 9e7 + 5;
struct Node{
    int pairs[4];
}arr[N];
int n;
long long ans = INT_MIN;
void dfs(int i, long long res, int a, int b, int c){
    if(i > n) {
        ans = max(ans, res);
        return ;
    }
    else{
        if(((a + 1) << 1) <= n)
            dfs(i + 1, res + arr[i].pairs[1], a + 1, b, c);
        if(((b + 1) << 1) <= n)
            dfs(i + 1, res + arr[i].pairs[2], a, b + 1, c);
        if(((c + 1) << 1) <= n)
            dfs(i + 1, res + arr[i].pairs[3], a, b, c + 1);
    }
}
void solved(){

    cin >> n;
    for(int i = 1; i <= n;  i++)
        for(int j = 1; j <= 3; j ++)
            cin >> arr[i].pairs[j];
    dfs(1, 0, 0, 0, 0);
    cout << ans << endl;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= 3; j ++){
            arr[i].pairs[j] = 0;
        }
    }
    ans = 0;
    n = 0;
}
int main(){
    int t;
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t --){
        solved();
    }
}
