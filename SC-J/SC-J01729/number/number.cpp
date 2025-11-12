#include<bits/stdc++.h>
using namespace std;
string s;
int numList[10]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if('0'<=s[i]&&s[i]<='9'){
            numList[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<numList[i];j++){
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}