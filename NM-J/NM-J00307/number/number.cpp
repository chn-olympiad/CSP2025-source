#include<bits/stdc++.h>
using namespace std;
int s[12];
int b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=1;i<=2;i++){
        cin>>s[i];
    }
    if(s[1]>s[2]){
        cout<<s[1]<<s[2];
    }
    else{
        cout<<s[2]<<s[1];
    }
}
