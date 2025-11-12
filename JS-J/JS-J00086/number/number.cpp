#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 114;
unsigned int tone[N];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    for(int i = 0 ; i < (int)s.size() ; i++){
        if(s[i]>='0'&&s[i]<='9'){
            tone[s[i]-'0']++;
        }
    }
    bool f = 1;
    for(int i = 9 ; i >= 0 ; i--){
        for(int j = 1 ; j <= tone[i] ; j++){
                //if(i == 0 && f){
                   // cout << 0 << endl;
                 //   return 0;
                //}
            cout << i;
            f = 0;
        }
    }
    cout << endl;
    return 0;
}
//wish I,Huangshengyan,Yuyaoxuan,Zhaoxicheng,Lihaocheng and Huangsiyuan can have a high score.
