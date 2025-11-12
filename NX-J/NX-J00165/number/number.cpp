#include<bits/stdc++.h>
using namespace std;
string s;
string s1="0123456789";
int t[100],f;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;s[i];i++){
        if(s[i]>='0'&&s[i]<='9'){
            t[s[i]-'0']++;
        }
    }
    for(int i=9;i>=1;i--){
        if(t[i]!=0&&i!=0){
            for(int j=1;j<=t[i];j++){
                cout<<s1[i];
                f=1;
            }
        }
    }
    if(f==1){
        for(int i=1;i<=t[0];i++){
            cout<<s1[0];
        }
    }else{
        if(t[0]>=1){
            cout<<'0';
        }
    }
    return 0;
}
