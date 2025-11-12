#include<bits/stdc++.h>
using namespace std;
const int maxn = 11;
int a[maxn][maxn],me = 0;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int pe = n*m;
    int x[pe+5];
    for(int i = 1; i <= pe;i++){
        cin >> x[i];
    }
    int w = 1,me = x[1];
    sort(x+1,x+pe+1,cmp);
    for(int i = 1;i <= n; i++){
        if (i % 2 == 1){
            for(int j = 1;j <= m; j++){
                a[i][j] = x[w];
                if (a[i][j] == me)cout << i << " " << j;
                w++;
            }
        }else{
                for(int j = m;j >= 1; j--){
                    a[i][j] = x[w];
                    if (a[i][j] == me)cout << i << " " << j;
                    w++;
                    }
                }
        }
    return 0;
}
