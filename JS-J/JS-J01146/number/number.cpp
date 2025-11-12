#include<bits/stdc++.h>
using namespace std;
long long num[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        int x=str[i]-'0';
        if(x>=0&&x<=9) num[x]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=num[i];j++) cout<<i;
    }
    return 0;
}
