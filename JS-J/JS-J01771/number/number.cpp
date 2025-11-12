#include<bits/stdc++.h>
using namespace std;
int cnt[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')cnt[s[i]-'0']++;
    }for(int i=9;i>=0;i--){
        for(int j=1;j<=cnt[i];j++)cout<<i;
    }
    return 0;
}
