#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]-'0'<10){
            a[n]=s[i]-'0';
            n++;
        }
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
