#include<bits/stdc++.h>
using namespace std;


int n , t , a[100003][5] , q[100003][5][2] , num , p[100003];

void dfs(int id , int ans , int a1 , int a2 , int a3 , int x){
    if(id > n){
        num = max(num , ans);
        return ;
    }
    if(a1+a2+a3>n)return ;
    p[a1+a2+a3] = max(p[a1+a2+a3] , ans);
    if(0){
        if(q[id][x][0] <= ans){
            if(q[id][x][0] == ans){
                if(x == 1)q[id][x][1] = min(q[id][x][1] , a1);
                if(x == 2)q[id][x][1] = min(q[id][x][1] , a2);
                if(x == 3)q[id][x][1] = min(q[id][x][1] , a3);
            }
            else {
                q[id][x][0] = ans;
                if(x == 1)q[id][x][1] = a1;
                if(x == 2)q[id][x][1] = a2;
                if(x == 3)q[id][x][1] = a3;
            }

        }

    }
    if(a1 < n/2 && p[a1+a2+a3+1] <= ans+a[id][1]+max(a[id+1][1] , max(a[id+1][2] , a[id+1][3])) && 1)dfs(id+1 , ans+a[id][1] , a1+1 , a2 , a3 , 1);
    if(a2 < n/2 && p[a1+a2+a3+1] <= ans+a[id][2]+max(a[id+1][1] , max(a[id+1][2] , a[id+1][3])) && 1)dfs(id+1 , ans+a[id][2] , a1 , a2+1 , a3 , 2);
    if(a3 < n/2 && p[a1+a2+a3+1] <= ans+a[id][3]+max(a[id+1][1] , max(a[id+1][2] , a[id+1][3])) && 1)dfs(id+1 , ans+a[id][3] , a1 , a2 , a3+1 , 3);
}

int main(){
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    cin >> t;
    for (int d = 1;d <= t;d++){
        num = 0;
        cin >> n;
        for (int i = 1;i <= n;i++){
            q[i][1][0] = q[i][2][0] = q[i][3][0] = -1;
            q[i][1][1] = q[i][2][1] = q[i][3][1] = INT_MAX;
        }
        for (int i = 1;i <= n;i++){
            p[i] = -1;
        }
        for (int i = 1;i <= n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }

        dfs(1 , 0 , 0 , 0 , 0 , -1);
        cout << num << '\n';
    }
    return 0;
}
