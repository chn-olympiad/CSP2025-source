#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,q;
string s[N][2];
string t[2];
int lst[N];
vector<int>v[N];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> s[i][0] >> s[i][1];
        int fl = -1;
        for(int j = 0;j < s[i][0].size();j++){
            if(s[i][0][j] != s[i][1][j]){
                lst[i] = j;
                if(fl == -1){
                    fl = j;
                }
            }
        }
        v[lst[i]-fl].push_back(i);
    }
    for(int i = 1;i <= q;i++){
        cin >> t[0] >> t[1];
        int ls = 0,fl = -1;
        for(int j = 0;j < t[0].size();j++){
            if(t[0][j] != t[1][j]){
                ls = j;
                if(fl == -1){
                    fl = j;
                }
            }
        }
        int an = 0;
        for(auto j:v[ls-fl]){
            int l = ls-lst[j],r = ls+(s[j][0].size()-lst[j]-1);
            if(l >= 0 && l <= fl && r < t[0].size()){
                bool fl = 1;
                for(int x = 0;x < s[j][0].size();x++){
                    if(s[j][0][x] != t[0][x+l] || s[j][1][x] != t[1][x+l]){
                        fl = 0;
                        break;
                    }
                }
                an += fl;
            }
        }
        cout << an << '\n';
    }
}
