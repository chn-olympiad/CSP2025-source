#include<bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int x , int y){
    return x > y;
}

int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    int n , m , u , v , x , ans1 , ans2;
    cin >> n >> m;

    u = n *  m;
    for(int i = 1 ; i <= u ; i ++){
        cin >> a[i];
    }
    v = a[1];
    sort(a + 1 , a + u + 1 , cmp);

    for(int i = 1 ; i <= u ; i ++){
        if(v == a[i]){
            x = i;
        }
    }

    ans1 = (x - 1) / n + 1;
    if(ans1 % 2 == 1){
        ans2 = (x - 1) % n + 1;
    }
    else{
        ans2 = n - (x - 1) % n;
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}
