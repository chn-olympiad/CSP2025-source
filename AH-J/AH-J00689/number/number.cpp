#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int in=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[++in]=s[i]-'0';
        }
    }
    sort(a+1,a+1+in);
    for(int i=in;i>=1;i--){
        printf("%d",a[i]);
    }
    return 0;
}
