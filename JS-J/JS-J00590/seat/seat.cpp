#include<bits/stdc++.h>
using namespace std;

int mp[105][105];
int n, m;
int a[10005];

bool cmp(int x, int y){
    return x>y;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int len = n*m;
    for(int i = 1;i<=len;i++){
        cin >> a[i];
    }
    int p = a[1];
    sort(a+1, a+1+len, cmp);
    int cnt = 1;
    for(int j = 1;j<=m;j++){
        if(j%2 == 0){
            for(int i = n;i>=1;i--){
                mp[i][j] = a[cnt];
                cnt++;
                if(mp[i][j] == p){
                    cout << j << " " << i;
                    return 0;
                }
            }
        }else{
            for(int i = 1;i<=n;i++){
                mp[i][j] = a[cnt];
                cnt++;
                if(mp[i][j] == p){
                    cout << j << " " << i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
