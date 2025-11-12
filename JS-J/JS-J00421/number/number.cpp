#include<bits/stdc++.h>
using namespace std;
const int MAXN = 15 + 10;
int cnt[MAXN];
int main(){
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    vector<int> a;
    for(int i = 0 ; s[i] ; ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            cnt[s[i] - '0']++;
        }
    }
    for(int i = 9 ; i >= 0 ; --i){
        while(cnt[i]){
            cout<<i;
            cnt[i]--;
        }
    }
    return 0;
}
