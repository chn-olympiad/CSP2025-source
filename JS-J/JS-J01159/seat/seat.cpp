#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m;
int s[N][N];
int cun[N*N];
int step = 0;
int d = 0;
int y = 1,x = 1;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i<n*m;i++){
        cin >> cun[i];
    }
    d = cun[0];
    sort(cun,cun+(n*m),cmp);

    s[y][x] = cun[step];
    while(step < n*m){
        while(y < n){
            s[++y][x] = cun[++step];
        }
        s[y][++x] = cun[++step];
        while(y > 1){
            s[--y][x] = cun[++step];
        }
        s[y][++x] = cun[++step];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i][j] == d){
                cout << j << " " << i;
                return 0;
            }
        }
    }
    return 0;
}
