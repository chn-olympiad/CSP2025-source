#include<bits/stdc++.h>
using namespace std;
string s;
int num[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            num[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=num[i];j>=1;j--){
            printf("%d",i);
        }
    }
    return 0;
}
