#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll num = 0,sign = 1;char ch = ' ';
    while(ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1),ch = getchar();
    while(ch >= '0' && ch <= '9') num = (num << 3) + (num << 1) + ch - '0',ch = getchar();
    return sign == 1 ? num : -num;
}
ll n,m,a1,ans = 0,sum = 1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n = read();m = read();a1 = read();
    for(int i = 2;i <= n * m;i++) sum += (a1 < read());
    for(int i = 1;i <= m;i++){
        if(i % 2) for(int j = 1;j <= n;j++){
            ans++;if(sum == ans){
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
        else for(int j = n;j >= 1;j--){
            ans++;if(sum == ans){
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
    }
    return 0;
}
