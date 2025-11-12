#include<iostream>
using namespace std;
string s;
long long numbers[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if('0'<=s[i] && '9'>=s[i]){
            numbers[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<numbers[i];j++){
            cout<<i;
        }
    }
    return 0;
}
