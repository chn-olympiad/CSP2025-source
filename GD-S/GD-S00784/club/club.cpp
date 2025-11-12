#include <bits/stdc++.h>

using namespace std;

struct ppl{
    int x, y, z, best, best_value, second, second_value;
};

bool cmp(ppl a, ppl b){
    return (a.best_value - a.second_value) < (b.best_value - b.second_value);
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int n2 = n / 2;
        vector<ppl> arr(n);
        vector<vector<int>> hire(4);
        for(int i = 0; i < n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            arr[i].x = a;
            arr[i].y = b;
            arr[i].z = c;
            int mx = max(a, max(b, c));
            int mi = min(a, min(b, c));
            if(mx == a){
                arr[i].best = 1;
                arr[i].best_value = a;
                if(mi == b){
                    arr[i].second = 3;
                    arr[i].second_value = c;
                }
                if(mi == c){
                    arr[i].second = 2;
                    arr[i].second_value = b;
                }
            }
            else if(mx == b){
                arr[i].best = 2;
                arr[i].best_value = b;
                if(mi == a){
                    arr[i].second = 3;
                    arr[i].second_value = c;
                }
                if(mi == c){
                    arr[i].second = 1;
                    arr[i].second_value = a;
                }
            }
            else if(mx == c){
                arr[i].best = 3;
                arr[i].best_value = c;
                if(mi == b){
                    arr[i].second = 1;
                    arr[i].second_value = a;
                }
                if(mi == a){
                    arr[i].second = 2;
                    arr[i].second_value = b;
                }
            }
            // cerr << arr[i].best << " " << arr[i].best_value << " " << arr[i].second << " " << arr[i].second_value << endl;
        }
        for(int i = 0; i < n; i++){
            hire[arr[i].best].push_back(i);
        }
        //cerr << hire[3].size() << " " << n2 << endl;
        if(hire[1].size() <= n2 && hire[2].size() <= n2 && hire[3].size() <= n2){
            long long ans = 0;
            for(int i = 0; i < n; i++){
                //cerr << arr[i].best_value << endl;
                ans += arr[i].best_value;
            }
            cout << ans << endl;
            continue;
        }
        else if(hire[1].size() > n2){
            vector<ppl> ls(n);
            int x = 0;
            for(int i = 0; i < n; i++){
                if(arr[i].best == 1){
                    ls[x] = arr[i];
                    x++;
                }
            }
            ls.resize(x);
            sort(ls.begin(), ls.end(), cmp);
            long long ans = 0;
            for(int i = 0; i < n; i++){
                ans += arr[i].best_value;
            }
            for(int i = 0; i < hire[1].size() - n2; i++){
                ans = ans - ls[i].best_value + ls[i].second_value;
            }
            cout << ans << endl;
            continue;
        }
        else if(hire[2].size() > n2){
            vector<ppl> ls(n);
            int x = 0;
            for(int i = 0; i < n; i++){
                if(arr[i].best == 2){
                    ls[x] = arr[i];
                    x++;
                }
            }
            ls.resize(x);
            sort(ls.begin(), ls.end(), cmp);
            long long ans = 0;
            for(int i = 0; i < n; i++){
                ans += arr[i].best_value;
            }
            for(int i = 0; i < hire[2].size() - n2; i++){
                ans = ans - ls[i].best_value + ls[i].second_value;
            }
            cout << ans << endl;
            continue;
        }
        else if(hire[3].size() > n2){
            vector<ppl> ls(n);
            int x = 0;
            for(int i = 0; i < n; i++){
                if(arr[i].best == 3){
                    ls[x] = arr[i];
                    x++;
                }
            }
            ls.resize(x);
            sort(ls.begin(), ls.end(), cmp);
            //for(auto sdf : ls) cerr << sdf.best << " " << sdf.best_value << " " << sdf.second << " " << sdf.second_value << endl;
            long long ans = 0;
            for(int i = 0; i < n; i++){
                ans += arr[i].best_value;
            }
            for(int i = 0; i < hire[3].size() - n2; i++){
                ans = ans - ls[i].best_value + ls[i].second_value;
            }
            cout << ans << endl;
            continue;
        }
    }
    return 0;
}