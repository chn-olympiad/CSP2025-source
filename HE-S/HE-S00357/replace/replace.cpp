#include<bits/stdc++.h>
using namespace std;
int n , q;
map<pair<string,string>,int>mp;
string substr_(string s,int l , int r){
    string k = "";
    for(int i = l ; i <= r ; i++){
        k += s[i];
    }
    return k;
}
int main(){ 
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        string s1 , s2;
        cin >> s1 >> s2;
        mp[{s1,s2}]++;
    }
    for(int i = 1;i <= q;i++){
        string t1 , t2;
        cin >> t1 >> t2;
        int lcp = -1 , lep = t1.size();
        for(int i = 0 ; i < t1.size();i++){
            if(t1[i] != t2[i])break;
            lcp = i;
        }
        for(int i = t1.size() - 1; i >= 0;i--){
            if(t1[i] != t2[i])break;
            lep = i;
        }
        if(lep == t1.size() and lcp == -1){
            cout << mp[{t1 , t2}] << endl;
            continue;
        }
        string ss1 = "" , ss2 = "";
        for(int i = lcp + 1;i <= lep - 1;i++){
            ss1 += t1[i];
            ss2 += t2[i];
        }
        int ans = mp[{ss1 , ss2}];
        for(int i = lcp ; i >= 0 ; i--){
            string str1 = "" , str2 = "";
            for(int j = i ;j < lcp;j++)str1 += t1[i] , str2 += t2[i];
            str1 += ss1 , str2 += ss2;
            for(int j = lep ; j < t1.size();j++){
                ans += mp[{str1 , str2}];
                if(j != t1.size() - 1){
                    str1 += t1[j];
                    str2 += t2[j];
                }
            }
        }
        cout << ans << endl;
    }





    return 0;
}