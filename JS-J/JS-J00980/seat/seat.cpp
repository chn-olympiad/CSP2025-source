#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    vector <int> v;
    cin >> n >> m;
    for (int i = 0;i < n * m;i++){
        int tf;
        cin >> tf;
        v.push_back(tf);
    }
    int t = v[0],tid = 0;
    for (int i = 1;i <= v.size();i++){
        for (int j = 0;j < v.size() - i;j++){
            if (v[j] < v[j + 1]){
                if (v[j] == t){
                    tid++;
                }
                else if (v[j + 1] == t){
                    tid--;
                }
                swap(v[j],v[j + 1]);
            }
        }
    }
    if (tid + 1 <= n){
        cout << 1 << ' ' << tid + 1;
    }
    else if ((tid + 1) % n == 0){
        if (((tid + 1) / n) % 2 == 1){
            cout << (tid + 1) / n << ' ' << n;
        }
        else{
            cout << (tid + 1) / n << ' ' << 1;
        }
    }
    else{
        cout << (tid + 1) / n + 1 << ' ';
        if (((tid + 1) / n + 1) % 2 == 1){
            cout << (tid + 1) % n;
        }
        else{
            cout << n - (tid + 1) % n + 1;
        }
    }
    return 0;
}
