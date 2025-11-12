#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(cnt,0,sizeof(cnt));
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(isdigit(s[i])){
            ++cnt[int(s[i]-'0')];
        }
    }for(int i=9;i>=0;--i){
        while(cnt[i]--)cout<<i;
    }cout<<endl;
    return 0;
}

