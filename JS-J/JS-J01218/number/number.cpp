#include<bits/stdc++.h>
using namespace std;
char str[1000000];int t[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(t,0,sizeof(t));
    cin>>str;
    for(int i=0;i<strlen(str);i++){
        if('0'<=str[i]&&str[i]<='9'){
            t[str[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=t[i];j++){
            cout<<i;
        }
    }
    return 0;
}
