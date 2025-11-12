#include<bits/stdc++.h>
using namespace std;
string s[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=1;i<=1000000;i++){
        cin>>s[i];
    }
    for(int i=1;i<=1000000;i++){
        cout<<s[i];
    }
    return 0;
}
