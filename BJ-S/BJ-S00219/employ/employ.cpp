#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 998244353;
int n;
void solved(){
    srand(time(0));
    cout << rand()%N;
}
int main(){
    int t = 1;
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    while(t --){
        solved();
    }
}

