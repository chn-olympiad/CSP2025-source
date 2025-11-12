#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int ls=s.length();
    for(int i=0;i<ls;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[i]=s[i]-'0';
        }else{
            a[i]=10;
        }
    }
    sort(a,a+ls);
    for(int i=0;i<ls;i++){
        if(a[i]==10) continue;
        else{
            cout<<a[i];
        }
    }
    return 0;
}