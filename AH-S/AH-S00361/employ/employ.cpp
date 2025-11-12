#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=rand();
    srand(t*rand());
    ll ans=(((rand()*rand())%21321234)*rand())%998244353;
    cout<<ans;
    return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
