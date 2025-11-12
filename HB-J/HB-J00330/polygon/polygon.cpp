#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> &vec, bool fbegin, int fcount = 0, int fmax = 0, int d = 0, int ffront = 0){
    if(fbegin){
        int s = 0;
        for(int i = 3; i <= vec.size(); i++){
            s += dfs(vec, 0, i);
            s %= 998244353;
        }
        return s;
    }

    if(fcount == 0){
        return (d > fmax * 2);
    }
    int s = 0;
    for(int i = ffront; i < vec.size(); i++){
        int kmax = fmax;
        int n = vec[i];
        if(n > fmax){
            kmax = n;
        }
        s += dfs(vec, 0, fcount - 1, kmax, d+n, i+1);
        s %= 998244353;
    }
    return s;
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n;
    vector<int> vec;
    cin >> n;
    for(int i = 0; i < n; i++){
        int q;
        cin >> q;
        vec.push_back(q);
    }

    cout << dfs(vec, 1);

    fclose(stdin); fclose(stdout);
}

