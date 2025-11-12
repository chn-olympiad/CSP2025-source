#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int num[maxn];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin>>s;
    int len = s.size(), idx = 0;
    for(int i = 0;i < len;++i){
        if(s[i] >= '0' && s[i] <= '9'){
            //is a number
            num[++idx] = (int)(s[i] - '0');
        }
    }
    sort(num + 1, num + idx + 1);
    for(int i = idx;i >= 1;--i){
        cout<<num[i];
    }
    cout<<'\n';
    return 0;
}
