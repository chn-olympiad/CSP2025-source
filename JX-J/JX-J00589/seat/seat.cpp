#include<bits/stdc++.h>
using namespace std;
int n, m, a[10100], b[105][105], s;
bool cmp(int x, int y){
    return x>y;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    for(int i = 0; i<n * m; i++)cin>>a[i];
    s = a[0];
    sort(a, a+n*m, cmp);
    int k = 0;
    for(int i = 1; i <= m; i++){
        if(i%2==1)
            for(int j = 1; j<= n; j++){
                if(s == a[k]) {
                    cout<<i<<' '<<j;
                    return 0;
                }
                k++;
            }
        else
            for(int j = n; j>0; j--){
                if(s == a[k]) {
                    cout<<i<<' '<<j;
                    return 0;
                }
                k++;
            }
    }
    return 0;
}
