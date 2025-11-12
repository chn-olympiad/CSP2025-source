#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(0);
    int x;
    for (int i=1; i<=n; i++){
        cin >> x;
        a.push_back(x);
    }
    int cnt = 0;
    for (int i=3; i<=n; i++){
        for (int x=1; x<=n; x++){
            for (int y=x+1; y<=n; y++){
                for (int z=y+1; z<=n; z++){
                    if (i==3){
                        if (a[x]+a[y]>a[z] && a[x]+a[z]>a[y] && a[y]+a[z]>a[x] && x!=y!=z){
                            cnt ++;
                        }
                    }
                }
            }
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
