#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,t="";
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
    }
    int flag=1;
    for(int i=9;i>=1;i--){
        if(a[i]>0){flag=0;
            for(int j=1;j<=a[i];j++) cout<<i;}
    }
    if(flag) cout<<0;
    else for(int i=1;i<=a[0];i++) cout<<0;
    return 0;
}
