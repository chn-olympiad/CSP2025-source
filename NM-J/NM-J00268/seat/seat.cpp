#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110], mp[20][20];
int c;
void dfs(int x, int y, int cnt){
    mp[x][y]=a[cnt];
    if(a[cnt] == c){
        cout << x << " " << y;
        return ;
    }
    if(x%2){
        int ny=y+1;
        if(ny>n)dfs(x+1, y, cnt+1);
        else dfs(x, ny, cnt+1);
    }else{
        int ny=y-1;
        if(ny<1)dfs(x+1, y, cnt+1);
        else dfs(x, ny, cnt+1);
    }
}
bool cmp(int A, int B){
    return A>B;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)cin >> a[i];
    c = a[1];
    sort(&a[1], &a[n*m+1], cmp);
    dfs(1, 1, 1);
    return 0;
}
