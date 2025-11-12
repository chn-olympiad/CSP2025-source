#include<bits/stdc++.h>
using namespace std;
int cnt[10];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            int num=s[i]-'0';
            cnt[num]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<cnt[i];j++) cout<<i;
    }
    return 0;
}
