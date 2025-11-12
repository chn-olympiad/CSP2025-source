#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int pos=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9') a[pos++]=s[i]-'0';
    }
    sort(a+1,a+pos);
    for(int i=pos-1;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
