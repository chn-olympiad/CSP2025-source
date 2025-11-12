#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    for(int i = s.length()-1;i >= 0;i--){
        if(s[i] >= '0'&&s[i] <= '9'){
            cout<<s[i];
        }
    }
    return 0;
}
