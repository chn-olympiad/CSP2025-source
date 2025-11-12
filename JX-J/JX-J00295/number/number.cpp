#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s+1;
    for(int i=1;;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
        else{
            if(s[i]<'a'||s[i]>'z')break;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
