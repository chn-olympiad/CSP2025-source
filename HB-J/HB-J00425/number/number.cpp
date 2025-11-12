#include<bits/stdc++.h>
using namespace std;
string s;
bool fl;
int a[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
    }
    fl=1;
    for(int i=1;i<=9;i++){
        if(a[i]){
            fl=0;
            break;
        }
    }
    if(fl){
        cout<<0;
        return 0;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
