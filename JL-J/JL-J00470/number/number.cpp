#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
bool cmp(int x,int y){
    return x > y;
} int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long cnt = 0;
    string s;
    getline(cin,s);
    for(long long i=0;i<s.size();i++){
        if('0' <= s[i] && s[i] <= '9'){
            a[i] = s[i] - '0';
            cnt++;
        }
    } sort(a,a+s.size(),cmp);
    for(long long i=0;i<cnt;i++){
        cout << a[i];
    } return 0;
}
