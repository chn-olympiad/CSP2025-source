#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
vector <int> num;
bool cmp(int x,int y) {
    return x>y;
}
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","W",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i) {
        if(0<=s[i]-'0' && 9>=s[i]-'0') {
            num.push_back(s[i]-'0');
        }
    } sort(num.begin(),num.end(),cmp);
    for(int i=0;i<num.size();++i) {
        printf("%d",num[i]);
    }
    return 0;
}
