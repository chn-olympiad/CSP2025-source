#include<bits/stdc++.h>
using namesapce std;
int n,m,a[105],sum,cnt;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin >> a[i];
    }
    sum = a[1];
    sort(a);
    for(int i = 1;i <= n*m;i++){
        if(a[i] == sum){
            cnt = i;
            break;
        }
    }
    if(cnt%(2*n) == 0){
        cout << cnt/n << 1 << endl;
        return 0;
    }
    else{
        if(cnt%(2*n) <= n){
            cout << cnt/n << cnt%(2*n) << endl;
        }
        if(cnt%(2*n) > n){
            cout << cnt/n << n-cnt%(2*n) << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}