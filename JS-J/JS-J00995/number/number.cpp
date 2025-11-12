#include<bits/stdc++.h>
using namespace std;
string s;
int a[15],t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
            t++;
        }
    }
    if(a[0]==t){
        cout<<0<<endl;
        return 0;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
