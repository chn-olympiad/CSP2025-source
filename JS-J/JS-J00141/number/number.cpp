#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            int x=s[i]-'0';
            a.push_back(x);
        }
    }

    sort(a.begin(),a.end());
    for(int i=a.size()-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
