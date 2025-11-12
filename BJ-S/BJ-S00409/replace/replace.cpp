#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
int n, q;
struct node{
    int x1, y1;
};
vector<node> a[maxn * 2];

void solve(){

    cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        string cin1, cin2;
        cin >> cin1 >> cin2;

        int len = cin1.size();
        cin1 = ' ' + cin1;
        cin2 = ' ' + cin2;
        int xx, yy, xx1, yy1;
        for(int j = 1; j <= len; j ++){
            if(cin1[j] == 'b'){
                xx = j - 1;
                xx1 = len - j;
                break;
            }
        }
        for(int j = 1; j <= len; j ++){
            if(cin2[j] == 'b'){
                yy = j - 1;
                yy1 = len- j;
                break;
            }
        }
        //cout << xx <<" " << xx1 << " " << yy - xx << endl;
        a[yy - xx + maxn].push_back({xx, xx1});
    }

    while(q --){

        string s, t;
        cin >> s >> t;
        if(s.size() != t.size()){
            cout << 0 << endl;
            continue;
        }

        int len = s.size();

        s = ' ' + s;
        t = ' ' + t;


        int now, ne;
        for(int i = 1; i <= len; i ++){
            if(s[i] == 'b'){
                now = i - 1;
            }
            if(t[i] == 'b'){
                ne = i - 1;
            }
        }
        //cout << now << ne << endl;
        int ans = 0;
        for(auto i : a[ne - now + maxn]){
            //cout << i.x1 <<" " << i.y1 << endl;
            if(now >= i.x1 && len - now - 1 >= i.y1){
                //cout << i.x1 <<" " << i.y1 << endl;
                ans ++;
            }
        }
        cout << ans << endl;
    }

}

int main(){

    ios::sync_with_stdio();
    cin.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    solve();

    return 0;
}
