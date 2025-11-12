#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int s[15][15];
bool cmp(int a, int b){
    return a > b;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i = 1;i <= n * m;i++){
        cin>>a[i];
    }
    int r = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int x = 1, y = 1;
    bool w = true;
    bool wfwf = false;
    for(int i = 1;i <= n * m;i++){
        s[x][y] = a[i];
        if((x == n || x == 1) && wfwf == true){
            y += 1;
            if(w == true){
                w = false;
            }else{
                w = true;
            }
            wfwf = false;
            continue;
        }
        if(w == true){
            x += 1;
            wfwf = true;
        }else{
            x -= 1;
            wfwf = true;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(s[i][j] == r){
                cout<<j<<" "<<i;
                return 0;
            }
            //cout<<s[i][j]<<" ";
        }
        //cout<<endl;
    }
    return 0;
}
