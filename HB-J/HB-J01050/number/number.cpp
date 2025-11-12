#include<bits/stdc++.h>
using namespace std;
int jishu[10];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(char c : s){
        if(c>='0'&&c<='9')jishu[c-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<jishu[i];j++)cout<<i;
    }
    return 0;
}
