#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,a[i][j];
    cin >> n;
    for(int i = 1;i <= n;i++){
        int m;
        cin >> m;
        for(int j =1;j <= m;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        cout << n+m << " " << n+m << " " << n+m;
    }
    return 0;
}
