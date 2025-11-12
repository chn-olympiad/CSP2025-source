#include <bits/stdc++.h>
using namespace std;
map<string, string> mp;
map<string, bool> mp2;
map<string, int> mp3;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    bool flag = true;
    for(int i = 1;i <= n;i++){
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1] = s2;
        mp2[s1] = true;
        int cnt = 0;
        int ind1, ind2;
        for(int i = 0;i < s1.size();i++){
            if(s1[i] != 'a' && s1[i] != 'b') flag = false;
            if(s1[i] == 'b'){cnt++; ind1 = i;}
        }
        if(cnt != 1) flag = false;
        cnt = 0;
        for(int i = 0;i < s2.size();i++){
            if(s2[i] != 'a' && s2[i] != 'b') flag = false;
            if(s2[i] == 'b'){cnt++; ind2 = i;}
        }
        if(cnt != 1) flag = false;
        int tmp = ind2 - ind1;
        mp3[s1] = tmp;
    }
    while(q--){
        string s1, s2;
        cin >> s1 >> s2;
        int cnt = 0;
        int ind1, ind2;
        for(int i = 0;i < s1.size();i++){
            if(s1[i] != 'a' && s1[i] != 'b') flag = false;
            if(s1[i] == 'b'){cnt++; ind1 = i;}
        }
        if(cnt != 1) flag = false;
        cnt = 0;
        for(int i = 0;i < s2.size();i++){
            if(s2[i] != 'a' && s2[i] != 'b') flag = false;
            if(s2[i] == 'b'){cnt++; ind2 = i;}
        }
        if(cnt != 1) flag = false;
        if(flag){
            int tmp = ind1 - ind2;
            long long ans = 0;
            for(auto it : mp3){
                if(it.second == tmp) ans++;
            }
            cout << ans << endl;
        }
        else{
            long long ans = 0;
            for(int i = 0;i < s1.size();i++){
                for(int j = i;j < s1.size();j++){
                    string ts = "";
                    for(int k = i;k <= j;k++) ts += s1[k];
                    if(mp2[ts]){
                        string ts2 = "";
                        for(int k = 0;k < i;k++) ts2 += s1[k];
                        ts2 += mp[ts];
                        for(int k = j+1;k < s1.size();k++) ts2 += s1[k];
                        if(ts2 == s2) ans++;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
