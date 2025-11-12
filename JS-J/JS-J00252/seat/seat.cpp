#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdout);
    freopen("seat.out","w",stdin);
    int n,m,a[110];
    int b = m*n;
    cin >> n >> m;
    for(int i = 0;i < b;i++){
       cin >> a[i];
    }
    int dis = a[0];
    for(int i = 0;i < b;i++){
        for(int j = i;j+1 < b;j++){
            if(a[j] < a[j+1]){
                int c = a[j];
                a[j] = a[j + 1];
                a[j+1] = c;
            }
        }
    }
    int ans;
    for(int i = 0;i < b;i++){
        if(a[i] == dis){
            ans = i+1;
            break;
        }
    }
    int r = ans % n;
    if(r == 0){
        r = n;
    }
    int l = ceil((ans - 0) * 1.0 / n) + 1;
    cout << l << " " << r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
