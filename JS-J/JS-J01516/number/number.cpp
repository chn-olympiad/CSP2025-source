#include<bits/stdc++.h>
using namespace std;
int ans[1000006],k;
char s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    while(cin >> s){
        if(s >= '0' && s <= '9'){
            ans[++k] = s - '0';
        }
    }
    sort(ans + 1,ans + k + 1);
    while(k--){
        if(k + 1){
            cout << ans[k + 1];
        }
    }
    return 0;
}
