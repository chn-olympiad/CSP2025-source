#include"bits/stdc++.h"
using namespace std;
string s;
int a[1000005];
int t=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int st=s.length();
    for(int i=0;i<st;i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[t]=s[i]-'0';
            t++;
        }
    }
    if(t==0){
        cout<<0;
        return 0;
    }
    sort(a,a+t,greater<int>());
    if(a[0]==0){
        cout<<0;
        return 0;
    }
    for(int i=0;i<t;i++){
        cout<<a[i];
    }
    return 0;
}
