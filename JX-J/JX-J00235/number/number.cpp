#include<bits/stdc++.h>
using namespace std;
string a;
vector<char>t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    for(int i = 0;i<a.size();i++){
        if('0'<=a[i]&&a[i]<='9'){
            t.push_back(a[i]);
        }
    }
    sort(t.begin(),t.end(),greater<>());
    for(int i = 0;i<t.size();i++){
        cout << t[i];
    }
    cout << '\n';
}
