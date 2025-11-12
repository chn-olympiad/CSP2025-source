#include<bits/stdc++.h>
using namespace std;
int l[100001];
long long x(int a){
    long long out = 1;
    for(int i = 1; i <= a; i++){
        out *= i;
        out = out % 998244353;
    }
    return out;
}
long long c(int a, int b){
    if(b >= a||b<=0) return 1;
    else return x(a)/(x(b)*x(a-b));
}
int main(){
    ifstream ifs;
    ifs.open("employ.in");
    int n,m;
    ifs >> n >> m;
    int s1 = 0;
    int s0 = 0;
    for(int i = 1; i<=n; i++){
            char c;
        scanf ("%c",&c);
        if(c == '0') s0++;
        else s1++;
    }
    int min1 = 1145141919;
    for(int i =1; i<=n;i++){
        int t;
    ifs >> t;
        min1 = min(min1,t);

    }
    ofstream ofs;
    ofs.open("employ.out");
    ofs << c(min1,s1)*c(n-min1,s0)% 998244353;
    return 0;
}
