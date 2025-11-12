//100pts
#include<bits/stdc++.h>
using namespace std;
string st;
int num[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>st;
    bool flag=true;
    for(int i=0;i<st.length();i++){
        if(st[i]<='9'&&st[i]>='0'){
            num[st[i]-'0']++;
          // if(st[i]-'0'!=0) flag=false;
        }
    }
    // if(flag){
    //     cout<<0;
    //     return 0;
    // }
    // else{
    for(int i=9;i>=0;i--){
        for(int j=1;j<=num[i];j++){
            cout<<i;
        }
    }
    // }
    return 0;
}