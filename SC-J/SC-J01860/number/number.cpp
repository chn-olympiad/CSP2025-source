#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

bool cmp(int x,int y){return x>y;}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    vector<int> a;
    string s;
    cin >> s;
    rep(i,0,s.size()-1){
        if(s[i]>='0'&&s[i]<='9') a.push_back(s[i]-'0');
    }
    sort(a.begin(),a.end(),cmp);

    for(int x:a) cout << x;
}
