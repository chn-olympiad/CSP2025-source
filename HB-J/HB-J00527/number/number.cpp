#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int ans[1000009] = {},x = 1;
    cin >> a;
    int r = a.size();
    for(int i = 0;i < r;i++){
        if(a[i] <= 'z' && a[i] >= 'a'){
            continue;
        }
        ans[x] = int(a[i] - '0');
        x++;
    }
    sort(ans+1,ans+1+x);
    for(int i = x;i > 1;i--){
        cout << ans[i];
    }
    return 0;
}
