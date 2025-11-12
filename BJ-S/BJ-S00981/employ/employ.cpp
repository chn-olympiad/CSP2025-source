#include<bits/stdc++.h>
using namespace std;
int n,m,c[1010],mod = 998244353,num,sum;
int ch[1010];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> ch[i];
        num += ch[i];
    }
    for(int i=1;i<=n;i++){
        cin >> c[i];
        sum += c[i];
    }
    cout << (sum - num) %mod;
    return 0;
}
