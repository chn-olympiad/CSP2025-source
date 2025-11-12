#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int>s_number;
    for(ll i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            s_number.push_back(s[i]-'0');
        }
    }
    sort(s_number.begin(),s_number.end());
    for(ll i=s_number.size()-1;i>=0;i--){
        printf("%d",s_number[i]);
    }
    return 0;
}
