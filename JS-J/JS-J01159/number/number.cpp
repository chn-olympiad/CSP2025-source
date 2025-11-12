#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
string s;
int num[N];
int cnt = 0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i<s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num[cnt] = (s[i]-'0');
            cnt++;
        }
    }
    sort(num,num+cnt);
    for(int i = cnt-1;i>=0;i--){
        cout << num[i];
    }
    return 0;
}
