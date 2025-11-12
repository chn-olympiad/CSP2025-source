#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
    }
    bool f=false;
    for(int i=9;i>0;i--){
        for(int j=1;j<=a[i];j++){
            f=true;
            cout<<i;
        }
    }
    if(!f)cout<<0;
    else for(int i=1;i<=a[0];i++)cout<<0;
    return 0;
}
