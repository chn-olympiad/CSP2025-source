#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n, a[100001];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int l = j + 1; l < n; l++){
                if((a[i] + a[j] + a[l]) > 2 * max(max(a[i], a[j]), a[l])){
                    ans++;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int l = j + 1; l < n; l++){
                for(int i0 = l + 1; i0 < n; i0++){
                    if((a[i] + a[j] + a[l] + a[i0]) > 2 * max(max(max(a[i], a[j]), a[i0]), a[l])){
                        ans++;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int l = j + 1; l < n; l++){
                for(int i0 = l + 1; i0 < n; i0++){
                    for(int j0 = i0 + 1; j0 < n; j0++){
                        if((a[i] + a[j] + a[l] + a[i0]) > 2 * max(max(max(max(a[i], a[j]), a[i0]), a[j0]), a[l])){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<++ans;

    return 0;
}


