#include <bits/stdc++.h>
using namespace std;

bool comp(int a,int b){
    return a<b;
}


int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    vector<int> vec(n);
    cin >> n >> m;
    string diff;
    cin >> diff;
    for(int i=0;i<n;i++){
        cout << vec[i];
    }
    cout << 998244353;
    return 0;
}
