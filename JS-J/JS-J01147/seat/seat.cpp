#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct Node{
    int id;
    int mark;
};
Node a[maxn];
int n, m;
bool cmp(Node X, Node Y){
    return X.mark > Y.mark;
}
int cnt = 0;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i].mark;
        a[i].id = i;
    }
    sort(a + 1, a + n * m + 1, cmp);
    int j = 0;
    while(j <= m){
        j++;
        for(int i = 1; i <= n; i++){
            cnt++;
            if(a[cnt].id == 1){
                cout << j << " " << i;
                return 0;
            } 
        }
        j++;
        for(int i = n; i >= 1; i--){
            cnt++;
            if(a[cnt].id == 1){
                cout << j << " " << i;
                return 0;
            } 
        }
    }
    return 0;
}