#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    if(s.size()==1){
        cout<<s;
    }else{
        for(int i=1;i<=s.size();i++){
        if(i>=0&&i<=9){
            cout<<i;
        }
    }
    }

    return 0;
}
