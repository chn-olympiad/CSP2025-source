#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            int c=int(s[i])-48;
            a[c]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
