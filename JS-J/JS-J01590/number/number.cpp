#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
    }
    bool ok=true;
    for(int i=1;i<10;i++){
        if(a[i]!=0) ok=false;
    }
    if(ok) cout<<0<<endl;
    else {
        for(int i=9;i>=0;i--){
            for(int j=0;j<a[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
