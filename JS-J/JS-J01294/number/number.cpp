#include<bits/stdc++.h>
using namespace std;
int t[1005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') t[s[i]-'0']++;
    }
    if(!t[9]&&!t[8]&&!t[7]&&!t[6]&&!t[5]&&!t[4]&&!t[3]&&!t[2]&&!t[1]) cout<<0;
    else{
        for(int i=9;i>=0;i--){
            for(int j=1;j<=t[i];j++) cout<<i;
        }
    }
    return 0;
}
