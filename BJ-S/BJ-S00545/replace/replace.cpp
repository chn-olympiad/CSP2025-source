#include<bits/stdc++.h>
using namespace std;
struct node{
    string x, y;
}a[200010], b[200010];
int n, q;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
    }
    for(int i = 1; i <= q; i++){
        cin >> b[i].x >> b[i].y;
        if(b[i].x.size() != b[i].y.size()){
            cout << 0 << endl;
            continue;
        }
        int cnt = 0;
        for(int j = 0; j < b[i].x.size(); j++){
            for(int k = j; k < b[i].x.size(); k++){
                string s1 = b[i].x.substr(0, j);
                string s2 = b[i].x.substr(j, k-j);
                string s3 = b[i].x.substr(k, b[i].x.size()-k);
                string s4 = b[i].y.substr(0, j);
                string s5 = b[i].y.substr(j, k-j);
                string s6 = b[i].y.substr(k, b[i].x.size()-k);
                if((s1 != s4)+(s2 != s5)+(s3 != s6) == 1){
                    if(s1 != s4){
                        for(int o = 1; o <= n; o++){
                            if(a[o].x == s1 && a[o].y == s4){
                                cnt++;
                            }
                        }
                    }else if(s2 != s5){
                        for(int o = 1; o <= n; o++){
                            if(a[o].x == s2 && a[o].y == s5){
                                cnt++;
                            }
                        }
                    }else if(s3 != s6){
                        for(int o = 1; o <= n; o++){
                            if(a[o].x == s3 && a[o].y == s6){
                                cnt++;
                            }
                        }
                    }
                }else{
                    continue;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
