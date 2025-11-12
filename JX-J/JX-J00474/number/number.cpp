#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w", stdout);
    string n;
    int maxn;
    vector <int> s, maxnn;
    getline(cin, n);
    for(int i = 0; i < n.size(); i++){
        if(n[i] >= '0' && n[i] <= '9') s.push_back(n[i]-'0');
    }
    while(1){
        int b;
        bool k = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != -1) break;
            if(s[i] == -1 && i == s.size()-1) k = true;
        }
        if(k) break;
        maxn = s[0];
        for(int i = 0; i < s.size(); i++){
            maxn = max(maxn, s[i]);
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == maxn){
                b = i;
                break;
            }
        }
        s[b] = -1;
        maxnn.push_back(maxn);
    }
    for(int i = 0; i < maxnn.size(); i++){
        cout << maxnn[i];
    }
    return 0;
}
