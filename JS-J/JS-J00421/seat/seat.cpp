#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 10;
int a[MAXN];
int sc = 0;
bool check(int cnt){
    return (a[cnt] == sc);
}
bool cmp(int x , int y){
    return x > y;
}
int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n , m;
    cin>>n>>m;
    for(int i = 1 ; i <= n * m ; ++i){
        cin>>a[i];
        if(i == 1){
            sc = a[i];
        }
    }
    sort(a + 1 , a + n * m + 1 , cmp);
    int x = 1 , y = 1 , cnt = 1;
    while(1){
        while(y <= m){
            if(check(cnt)){
                cout<<x<<" "<<y<<"\n";
                return 0;
            }
            //cout<<x<<" "<<y<<" "<<cnt<<" "<<a[cnt]<<"\n";
            cnt++;
            y++;
        }
        y--;
        x++;
        while(y >= 1){
            if(check(cnt)){
                cout<<x<<" "<<y<<"\n";
                return 0;
            }
            //cout<<x<<" "<<y<<" "<<cnt<<" "<<a[cnt]<<"\n";
            cnt++;
            y--;
        }
        x++;
        y++;
    }
    return 0;
}
