#include<bits/stdc++.h>
using namespace std;
const long long p = 998244353;
int c[550];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;cin >> n >> m;
    string s;cin >> s;
    for(int i = 1;i <= n;++i){cin >> c[i];}
    int ok=1;
    for(int i = 0;i < n;++i){
        if(s[i]!='1'){ok=0;break;}
    }
    if(ok){
        long long sum = 1;
        for(int i = 2;i <= n;++i){
            sum *= i;sum %= p;
        }
        cout << sum;
    }else if(n<=10){

	}
    return 0;
}
