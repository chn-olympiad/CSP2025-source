#include<bits/stdc++.h>
using namespace std;
int num[15]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string str="";
    cin>>str;
    for(int i=0;i<str.length();i++){
        if('0'<=str[i]&&str[i]<='9'){
            num[str[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(num[i]){
            cout<<i;
            num[i]--;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
