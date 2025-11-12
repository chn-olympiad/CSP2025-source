#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdin);
    int s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if("0"<=s[i]&&s[i]<="9"){
            cout<<i;
        }
    }
    return 0;
}
