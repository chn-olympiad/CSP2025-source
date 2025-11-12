#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();++i){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    bool all0=1;
    for(int i=1;i<=9;++i){
        if(a[i]){
            all0=0;
            break;
        }
    }
    if(all0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=9;i>=0;--i){
        for(int j=a[i];j>0;--j){
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}