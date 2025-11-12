#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    if(n >= 10000) return 0;
    vector<pair<string, string> > nn;
    for(int i=0;i<n;i++){
        string ta, tb;
        cin >> ta >> tb;
        nn.push_back(make_pair(ta, tb));
    }
    for(int qq=0;qq<q;qq++){
        string from, to;
        cin >> from >> to;
        vector<string> mo;
        for(auto pp : nn){
            string sec = pp.first;
            if(sec.size() <= from.size()){
                for(int i=0;i<=from.size()-sec.size();i++){
                    if(from[i] == sec[0]){
                        bool flag = 1;
                        for(int j=1;j<sec.size();j++){
                            if(sec[j] != from[i+j]){
                                flag = 0;
                                break;
                            }
                        }
                        if(flag){
                            //cout << sec << " " << from << endl;
                            mo.push_back(from.substr(0, i) + pp.second + from.substr(i+sec.size()));
                        }
                    }
                }
            }
            else{
                continue;
            }
        }
        int cnt=0;
        for(auto pp : mo){
            if(pp == to) cnt++;
        }
        cout << cnt << endl;
    }
}

