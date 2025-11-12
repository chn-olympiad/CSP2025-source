#include<bits/stdc++.h>
using namespace std;
string ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s;
    while(cin>>s){
        if(s>='0'&&s<='9'){
            ans+=s;
        }
    }
    sort(ans.rbegin(),ans.rend());
    cout<<ans;
    return 0;
}
