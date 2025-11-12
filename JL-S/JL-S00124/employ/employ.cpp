#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin >> n;
    long long acac=1;
    for(int i=1;i<=n;i++){
        acac*=i;
        acac%=998244353;
    }
    cout << acac/2;
    return 0;
}
//Ren5Jie4Di4Ling5%
//priority_queue<int,vector<int>,greater<int>>p;
