#include<bits/stdc++.h>
using namespace std;

int seat[1000];
int st[110][110];
int cnt;

bool cmp(int a,int b){
    return a >b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin >> n >>m;
    int R;
    for(int i = 1;i <= n*m;i ++)
        cin >> seat[i];

    R = seat[1];
    sort(seat+1,seat+1+n*m,cmp);
    int x = 0, y;
    while(1){
        x++;
        for(y = 1;y <= n;y ++){
            st[x][y] = seat[++cnt];
            if(st[x][y] == R){
                cout << x << ' '<< y;
                return 0;
            }
        }
        if(x == m) break;
        x++;
        for(y = n;y >= 1;y --){
            st[x][y] = seat[++cnt];
            if(st[x][y] == R){
                cout << x << ' '<< y;
                return 0;
            }
        }
        if(x == m) break;
    }

    return 0;
}
