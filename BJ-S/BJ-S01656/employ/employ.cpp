#include<bits/stdc++.h>
using namespace std;
long long n, m, c[1000010], o, u = 1;
char s[1000010];
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m>>s + 1;
    for(int i = 1; i <= n; i++){
        cin>>c[i];
        if(c[i] == 0){
            o++;
        }
    }
    if(m > n - o){
        cout<<"0";
        return 0;
    }
    for(int i = 2; i <= n; i++){
        u *= i;
        u %= 998244353;
    }
    cout<<u<<endl;
    return 0;
}

