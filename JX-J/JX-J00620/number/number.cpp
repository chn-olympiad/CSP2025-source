#include<bits/stdc++.h>
using namespace std;
int a[1000001],t=0;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            a[t]=int(s[i]-'0');
            t++;
        }
    }
    sort(a,a+t);
    for(int i=t-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
