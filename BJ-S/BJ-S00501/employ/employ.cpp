#include <iostream>
#include <string>
using namespace std;

bool tmp = false;

long long A(int n, int m){
    long long ans = 1;
    for(int i = m + 1; i <= n; i++){
        ans *= i;
        ans = ans % 998244353;
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            tmp = true;
        }
    }
    if(!tmp){
        cout << A(n, m) % 998244353;
    }else{
        cout << 998244352;
    }
    return 0;
}
