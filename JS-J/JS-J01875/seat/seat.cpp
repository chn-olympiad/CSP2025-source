#include <bits/stdc++.h>
using namespace std;
int a[101];
int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++){
        cin >> a[i];
    }int rs = a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int op = 1,cnt = 1;
    for (int i  =1; i <= m; i++){
        if (op){
            for (int j = 1;j <= n; j++,cnt++){
                if (a[cnt] == rs){
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }else{
            for (int j = n;j >= 1; j--,cnt++){
                if (a[cnt] == rs){
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }
        op = (op+1)%2;
    }
    return 0;
}
