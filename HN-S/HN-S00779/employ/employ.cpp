#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 550;
const int mod = 998244353;
int n, m;
string str;
int c[maxn];
ll jie[maxn];
int cnt0 = 0;

void pre(){
    jie[1] = 1;
    for(int i = 2; i <= n; i++)
        jie[i] = jie[i - 1] * i % mod;
}

int spja(){
    if(m > n - cnt0) return 0;
    else return jie[n];
}

int main(){
    freopen("employ3.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    pre();
    cin >> str;
    str = "0" + str;
    int flaga = 1;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        if(c[i] == 0) cnt0++;
        if(str[i] == '0') flaga = 0;
    }



    if(flaga) cout <<spja() <<endl;

    return 0;
}
