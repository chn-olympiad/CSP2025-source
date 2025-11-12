#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a;
    char s[a];
    cin>>s;
    for(int i=1;i<=a;++i){
        cin>>s;
        if(s[i]==1|s[i]==2|s[i]==3|s[i]==4|s[i]==5|s[i]==6|s[i]==7|s[i]==8|s[i]==9){
            cout<<s[i]<<endl;
        }else{
            continue;
        }
    }
    return 0;
}
