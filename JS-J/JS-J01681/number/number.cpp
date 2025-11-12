#include<bits/stdc++.h>
using namespace std;
int num[1000005];
int can[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++){
        if( (s[i]>='0') && (s[i]<='9') ){
            can[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(can[i]--){
            printf("%d",i);
        }
    }
    return 0;
}
