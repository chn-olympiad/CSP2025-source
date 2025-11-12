#include<iostream>
#include<cstdio>
using namespace std;
int b[15];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","W",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            b[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=b[i];j++){
            printf("%d",i);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
