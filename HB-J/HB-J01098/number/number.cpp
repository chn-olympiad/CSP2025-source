#include<bits/stdc++.h>
#define lxx 0
using namespace std;
int num[12];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9' && s[i]>='0'){
            num[int(s[i]-'0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        while(num[i]--){
            printf("%d",i);
        }
    }
    printf("\n");
    return lxx;
}