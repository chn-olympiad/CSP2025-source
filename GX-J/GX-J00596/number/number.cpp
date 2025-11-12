#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    vector<char> p;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z'){
            continue;
        }
        p.push_back(s[i]);
    }
    sort(p.begin(),p.end());
    for(int i=p.size();i>=0;i--){
        cout<<p[i];
    }
    cout<<endl;

    return 0;
}
