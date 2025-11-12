#include<bits/stdc++.h>
using namespace std;
string s;
int num[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')num[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(;num[i];num[i]--)cout<<i;
    }
    return 0;
}