#include<iostream>
#include<cstdio>
using namespace std;
string s;
int b[105];//1 ≤ |s| ≤ 10 ^6
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            b[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=b[i];j++){
            cout<<char(i+'0');
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
