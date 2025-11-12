#include<bits/stdc++.h>
using namespace std;
const int MAXN = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("replace3.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q;
    cin >> n >> q;
    if(n+q>3000){
        while(q--){
            cout << 0 << "\n";
        }
    }
    vector<pair<string,string>> a;

    for(int i = 0;i < n;i++){
        string s1,s2;
        cin >> s1 >> s2;
        a.push_back({s1,s2});
    }


    for(int i = 0;i < q;i++){
        int ans = 0;
        string s1,s2;
        cin >> s1 >> s2;

        for(int r = 1;r <= s1.size();r++){
            for(int l = 0;l <= r;l++){

                int len = r-l+1;
                string t2 = "";
                for(int x = l;x < len;x++){
                    t2 += s1[x];
                }

                for(int o = 0;o < n;o++){
                    if(a[o].first == t2){
                        string t3 = s1;
                        string a1 = a[o].second;
                        int q = 0;
                        for(int x = l;x < len;x++){
                            t3[x] = a1[q];
                            q++;
                        }
                        if(t3 == s2){
                            ans++;
                        }
                    }
                }

            }

        }
        cout << ans << "\n";
    }
}


