#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int NR = 2e5;
const LL P = 1e9 + 9;
const LL base = 10007;
string s[NR + 10][2];
string t1, t2;
// string st1, st2;
// int pi1[NR + 10];
// int pi2[NR + 10];
// void manacher(string &str, int pi[]){
//     int len = str.length();
//     pi[0] = pi[1] = 0;
//     for(int i = 2;i <= len;i++){
//         int j = pi[i - 1];
//         while(j > 0 && s[i - 1] != s[j + 1 - 1]) j = pi[j];
//         if(s[i - 1] == s[j + 1 - 1]) j++;
//         pi[i] = j;
//     }
//     return ;
// }
LL calh(string str){
    int len = str.length();
    LL ret = 0;
    for(int i = 0;i < len;i++){
        ret = (ret * base + str[i]) % P;
    }
    return ret;
}
map<pair<string, string>, int> mp;

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, T;
    scanf("%d%d", &n, &T);
    for(int i = 1;i <= n;i++){
        cin>>s[i][0]>>s[i][1];
        mp[{s[i][0], s[i][1]}]++;
    }
    while(T--){
        cin>>t1>>t2;
        int len = t1.length();
        int cnt = 0;
        for(int l = 0;l < len;l++){
            // printf("l=%d\n", l);
            if(t1.substr(0, l) != t2.substr(0, l)) break;
            // cout<<t1.substr(0, l)<<endl;
            // cout<<t2.substr(0, l)<<endl;
            string tmp1 = "", tmp2 = "";
            for(int r = l;r < len;r++){
                // printf("r=%d\n", r);
                tmp1 += t1[r];
                tmp2 += t2[r];
                // cout<<tmp1<<endl;
                // cout<<tmp2<<endl;
                if(mp.count({tmp1, tmp2})){
                    if(t1.substr(r + 1) == t2.substr(r + 1)){
                        cnt += mp[{tmp1, tmp2}];
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
/*
cd ~/replace && g++ replace.cpp -O2 -o replace && ./replace
*/