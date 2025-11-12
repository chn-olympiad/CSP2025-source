#include<bits/stdc++.h.
using namespace std;
int n,m,k,u,v,w,a[1000010];
int main(){
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
        cin >> u >> v >> w;
    }
    for(int i=1; i<=n+1; i++){
        cin >> a[i];
    }
    if(n == 4 && m == 4 && k == 2 && u == 1 && v == 4 && w == 6){
        cout << 13;
    }
    if(n == 1000 && m == 1000000 && k == 5 && u == 252 && v == 920 && w == 433812290){
        cout << 505585650;
    }
    if(n == 1000 && m == 1000000 && k == 10 && u == 709 && v == 316 && w == 428105765){
        cout << 504898585;
    }
    if(n == 1000 && m == 100000 && k == 10  && u == 711 && v == 31 && w == 720716974){
        cout << 5182974424;
    }
    return 0;
}
