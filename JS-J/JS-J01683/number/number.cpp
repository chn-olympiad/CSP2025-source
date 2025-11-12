#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000+5],k=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(int(s[i])-48>=0&&int(s[i])-48<=9){
            k++;
            a[k]=int(s[i]-48);
        }
    }
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--){
        cout<<a[i];
    }

    return 0;
}
