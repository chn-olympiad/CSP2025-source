#include<bits/stdc++.h>
using namespace std;
int a[1000005],h=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]<='9'){
            if(s[i]>='1')
            a[h]=s[i]-48;
            h++;
        }
    }
    sort(a,a+h+1);
    for(int i=h;i>1;i--){
        cout<<a[i];
    }
    return 0;
}
