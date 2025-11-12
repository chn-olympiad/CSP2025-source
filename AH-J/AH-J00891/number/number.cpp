#include<bits/stdc++.h>
using namespace std;
string s,max_num;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
        if('0'<=s[i]&&s[i]<='9'){
            max_num+=s[i];
        }
    }
    sort(max_num.begin(),max_num.end());
    reverse(max_num.begin(),max_num.end());
    cout<<max_num;

    return 0;
}
