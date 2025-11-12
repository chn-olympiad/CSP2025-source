#include<bits/stdc++.h>
using namespace std;
int a[1003];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int m=0;
    cin>>s;
    for(int i=1;i<s.size();i++){
        if(s[i]>'1'&&s[i]<'9'||s[i]=='1'||s[i]=='9'){
            m++;
            a[m]==s[i];
        }
    }
    for(int i=1;i<=m;i++){
    while(m>=i){
        int t=0;
        i=1;
        if(a[i]<a[i+1]){
            a[i]=t;
            a[i]=a[i+1];
            a[i+1]=t;
        }

    }
    }
    for(int i=1;i<=m;i++){
        cout<<a[i];
    }

    return 0;
}
