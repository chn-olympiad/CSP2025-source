#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
long long cnt = 1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    while(n >= 4){
        cnt *= n;
        n--;
        if(cnt >= 244 && cnt < 353){
            cnt %= 244;
        } else if(cnt >= 353 && cnt < 998){
            cnt %= 353;
        } else {
            cnt %= 998;
        }
    }
    cout << cnt;
    return 0;
}
