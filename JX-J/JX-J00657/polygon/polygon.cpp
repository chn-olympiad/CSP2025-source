#include <bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],cnt = 0;
void f(int d){
    int sum = 0,maxlen = 0;
    if(d > n){
        return;
    }
    if(d >= 4){
        for(int i = 1;i < d;i++){
            sum += a[d[i]];
            maxlen = max(maxlen,a[d[i]]);
        }
        if(sum > 2*maxlen) cnt++;
    }
    for(int i = b[d-1]+1;i <= n;i++){
        b[d] = i;
        f(d+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
}
    f(1);
    cout << cnt % 998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
