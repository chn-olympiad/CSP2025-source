#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
bool cmp (int a,int b) {
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (char c : s) {
        if (isdigit(c)) v.push_back(c-'0');
    }
    sort(v.begin(),v.end(),cmp);
    for (int num : v) cout<<num;
    return 0;
}
