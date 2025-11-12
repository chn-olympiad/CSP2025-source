#include<bits/stdc++.h>
using namespace std;
string s1[200010], s2[200010];
int l, r;
bool chk(string s){
    char a = 'a', b = 'b';
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == a) continue;
        else if(s[i] == b) cnt++;
        else return 0;
    }
    if(cnt == 1) return 1;
    return 0;
}
void check(string s, string t){
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]){
            cnt++;
            if(cnt == 1) l = i;
            r = i;
        }
    }
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    string t1, t2;
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
    while(q--){
        l = 0, r = 0;
        int cnt = 0;
        bool flag = 0;
        cin >> t1 >> t2;
        if(chk(t1) && chk(t2)){
            string t = "b";
            int tempt11 = t1.find(t), tempt12 = t1.size() - t1.find(t) - 1, tempt21 = t2.find(t), tempt22 = t2.size() - t2.find(t) - 1;
            for(int i = 1; i <= n; i++){
                int temps11 = s1[i].find(t), temps12 = s1[i].size() - s1[i].find(t) - 1, temps21 = s2[i].find(t), temps22 = s2[i].size() - s2[i].find(t) - 1;
                if(tempt11 >= temps11 && tempt12 >= temps12 && tempt21 >= temps21 && tempt22 >= temps22) cnt++;
            }
            cout << cnt << endl;
            continue;
        }
        check(t1, t2);
        string temp1 = t1.substr(l, r - l + 1), temp2 = t2.substr(l, r - l + 1);
        for(int i = 1; i <= n; i++){
            if(s1[i] == temp1 && s2[i] == temp2){
                flag = 1;
                cnt++;
            }
            if(s1[i] == t1 && s2[i] == t2){
                flag = 1;
                cnt++;
            }
        }
        if(!flag) cout << "0" << endl;
        else cout << cnt << endl;
    }
    return 0;
}
