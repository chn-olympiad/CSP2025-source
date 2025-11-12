#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

__int128 p[505];
void f();
void out(__int128 a){
    std::vector<int> num;
    while(a > 0){
        num.push_back(a % 1000000000);
        a /= 1000000000;
    }
    for(int i = num.size() - 1;i>=0;i--){
        cout<<num[i];
    }
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    f();
    int n;
    cin>>n;
    out(p[n] % 998244353);
    return 0;
}

void f(){
    p[1] = 1;
    for(int i = 2;i<=500;i++){
        p[i] = p[i-1] * i;
    }
}
