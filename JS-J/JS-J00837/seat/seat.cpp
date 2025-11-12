#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,score[105],seat[15][15],cnt,r,order,order1;
bool cmp(int x,int y){
    return x > y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> score[i];
    }
    r = score[1];
    sort(score + 1,score + 1 + n * m,cmp);
    for(int i = 1;i <= n * m;i++){
        if(score[i] == r){
            order = i % n;
            order1 = i / n;
            break;
        }
    }
    if(order){
        cout << order1 + 1;
        cout << ' ';
        if((order1) % 2){
            cout << n - order + 1 << endl;
        }
        else cout << order << endl;
        return 0;
    }
    else{
        cout << (order1);
        cout << ' ';
        if((order1) % 2 == 0) cout << 1 << endl;
        else cout << n << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
