#include<bits/stdc++.h>
using namespace std;
string s;
int mp[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            mp[s[i]-'0']++;
        }
    }
    if(mp[9]>=1){
        for(int i=1;i<=mp[9];i++){
            cout<<'9';
        }
    }
    if(mp[8]>=1){
        for(int i=1;i<=mp[8];i++){
            cout<<'8';
        }
    }
    if(mp[7]>=1){
        for(int i=1;i<=mp[7];i++){
            cout<<'7';
        }
    }
    if(mp[6]>=1){
        for(int i=1;i<=mp[6];i++){
            cout<<'6';
        }
    }
    if(mp[5]>=1){
        for(int i=1;i<=mp[5];i++){
            cout<<'5';
        }
    }
    if(mp[4]>=1){
        for(int i=1;i<=mp[4];i++){
            cout<<'4';
        }
    }
    if(mp[3]>=1){
        for(int i=1;i<=mp[3];i++){
            cout<<'3';
        }
    }
    if(mp[2]>=1){
        for(int i=1;i<=mp[2];i++){
            cout<<'2';
        }
    }
    if(mp[1]>=1){
        for(int i=1;i<=mp[1];i++){
            cout<<'1';
        }
    }
    if(mp[0]>=1){
        for(int i=1;i<=mp[0];i++){
            cout<<'0';
        }
    }
    return 0;
}
