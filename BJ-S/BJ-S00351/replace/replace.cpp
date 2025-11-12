#include<bits/stdc++.h>
using namespace std;
int n,q;
int ans;
pair<string,string> p[200004];
string t1,t2;
int main(){
    freopen("replace2.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n; i++){
        cin >> p[i].first >> p[i].second;
    }
    while(q--){

        ans = 0;
        //cout << '?';
        t1 = "",t2 = "";
        cin >> t1 >> t2;

        for(int i = 1;i <= n; i++){
            for(int j = 0;j <= t1.length() - p[i].first.length(); j++){
                if(t1.substr(j,p[i].first.length()) == p[i].first){
                    string t3 = t1.substr(0,j) + p[i].second + t1.substr(p[i].second.length()+j,t1.length()-p[i].first.length()-j);
                    //cout << t3 << '\n';
                    if(t3 == t2){
                        ans++;
                    }
                }
                //cout << "oi\n";
            }
        }
        cout << ans << '\n';
    }
    return 0;
    }
