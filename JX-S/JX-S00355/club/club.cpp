#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t;
int n;
vector<int> v1, v2, v3;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        long long ans = 0;
        v1.clear();
        v2.clear();
        v3.clear();
        for(int i = 1;i <= n;i++){
            int a, b, c;
            cin >> a >> b >> c;
            if(a >= b && a >= c){
                ans += a;
                v1.push_back(min(a - b, a - c));
            }else if(b >= a && b >= c){
                ans += b;
                v2.push_back(min(b - a, b - c));
            }else{
                ans += c;
                v3.push_back(min(c - a, c - b));
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sort(v3.begin(), v3.end());
        if(v1.size() > n / 2){
            int x = v1.size() - n / 2;
            for(int i = 0;i < x;i++) ans -= v1[i];
        }
        if(v2.size() > n / 2){
            int x = v2.size() - n / 2;
            for(int i = 0;i < x;i++) ans -= v2[i];
        }
        if(v3.size() > n / 2){
            int x = v3.size() - n / 2;
            for(int i = 0;i < x;i++) ans -= v3[i];
        }
        cout << ans << '\n';
    }
    return 0;
}//woshishabi
