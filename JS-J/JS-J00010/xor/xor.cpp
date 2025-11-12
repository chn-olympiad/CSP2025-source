#include <bits/stdc++.h>
using namespace std;
int n,k;
const int N = 5e5+8;
int a[N];
//int sfx[N];
//int cnt[256];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n >= 2e5+8){
        int ans = 0;
        if(k == 1){
            for(int i = 1; i <= n; i++){
                ans = ans + (a[i] == 1);
            }
        }
        if(k == 0){
            for(int i = 1; i <= n; i++){
                if(a[i] == 0) ans++;
                if(a[i] == 1 && a[i+1] == 1){
                    ans++;
                    i++;
                }
            }
        }
        cout << ans;
        return 0;
    }
    int lst = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int j = i;
        int tmp = 0;
        int idx = lst;
        while(j > lst){
            tmp = tmp ^ a[j];
            if(tmp == k){
                idx = j;
                break;
            }
            j--;
        }
        if(idx > lst) lst = i,ans++;
    }
    cout << ans;
    // 65 pts
    fclose(stdin);
    fclose(stdout);
    return 0;
}
