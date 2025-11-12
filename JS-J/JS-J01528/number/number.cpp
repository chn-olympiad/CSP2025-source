#include <bits/stdc++.h>
using namespace std;
string s;
string ans;
const int MAXN(1e6+5);
int a[10];//tong 0-9
int main(void){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    for(size_t i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
                a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]){
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}
