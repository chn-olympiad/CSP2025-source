#include<bits/stdc++.h>
using namespace std;

struct STU{
    int a , k;
}s[200];

int m , n;
int c;

bool t[20][20];

bool cmp(STU a1 , STU a2){
    return a1.a > a2.a;
}

void dfs(int x , int y , int k){
    if(k == 0){
        cout << y << " " << x;
        return; 
    }
    
    t[1][1] = 1;
    if(x + 1 <= n && t[x + 1][y] == 0){
        t[x + 1][y] = 1;
        dfs(x + 1 , y , k - 1);
    }else if(x - 1 >= 1 && t[x - 1][y] == 0){
        t[x - 1][y] = 1;
        dfs(x - 1 , y , k - 1);
    }else{
        dfs(x , y + 1 , k - 1);
    }
}

int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n * m ; i++){
        cin >> s[i].a;
        s[i].k = i;
    }

    // for(int i = 1 ; i <= n * m ; i++){
    //     cout << s[i].a << " " << s[i].k << endl;
    // }
    // cout << endl;
    
    sort(s + 1, s + 1 + n * m , cmp);

    // for(int i = 1 ; i <= n * m ; i++){
    //     cout << s[i].a << " " << s[i].k << endl;
    // }
    // cout << endl;
    
    for(int i = 1 ; i <= n * m ; i++){
        if(s[i].k == 1){
            c = i;
            break;
        }
    }
    dfs(1 , 1 , c - 1);
    return 0;
}