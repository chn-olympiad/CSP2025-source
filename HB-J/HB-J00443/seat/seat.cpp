#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],fs;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i ++) cin >> a[i];
    fs = a[1];
    sort(a + 1,a + n + 1);
    int x = 1,y = 1;
    for(int i = n;i >= 1;i --){
        if(a[i] == fs) cout << x << " " << y;
        else{
            if(y % 2 == 1){
                x ++;
                if(x == n) y ++;
            }
            else{
                x --;
                if(x == 1) y ++;
            }
        }
    }
    return 0;
}
