#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        a[i]=10;
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=int(s[i]-'0');
        }
    }
    sort(a,a+s.size(),cmp);
    for(int i=0;i<s.size();i++){
        if(a[i]!=10){
            cout<<a[i];
        }
    }
    return 0;
}
