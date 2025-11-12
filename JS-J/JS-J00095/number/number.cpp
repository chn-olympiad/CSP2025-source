#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    for(auto it:s){
        if(isdigit(it)){
            cout<<it;
        }
    }
    return 0;
}
