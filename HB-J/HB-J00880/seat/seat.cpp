#include <bits/stdc++.h>
using namespace std;
int n,m;
int sc[105][105];
int a[10005];
int xp = 1,yp = 1;
int cur = 1;
int a_sc;
int vis[105][105] = {0};
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> sc[i][j];
            a[cur] = sc[i][j];
            cur++;
        }
    }
    a_sc = sc[1][1];
    sort(a+1,a+cur,cmp);
    for(int i = 1;i <= cur;i++){
        if(a[i] == a_sc){
            cur = i;
            break;
        }
    }
    int op = 1;
    int t = 0;
    while(xp <= m){
        t++;
        if(t == cur){
            cout << xp << ' ' << yp;
            return 0;
        }
        vis[xp][yp] = 1;
        if(yp == 1 && xp > 1 && vis[xp][yp+1]){
            xp++;
            op = 1;
        }else if(yp == n && vis[xp][yp-1]){
            xp++;
            op = 0;
        }else{
            if(op == 1) yp++;
            else if(op == 0) yp--;
        }
    }
    return 0;
}
