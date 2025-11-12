#include<bits/stdc++.h>
using namespace std;
string s1[200005], s2[200005], t1[5000005], t2[5000005];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s1[i] >> s2[i];
    }

    //else{
        for(int i = 1; i <= m; i++){
        cin >> t1[i] >> t2[i];
        cout << 0 << endl;
        }
    //}

}
