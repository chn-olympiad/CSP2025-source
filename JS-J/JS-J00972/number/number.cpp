#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],x;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9' && s[i]>='0'){
            x++;
            a[x]=s[i]-'0';
        }
    }
    sort(a+1,a+1+x);
    for(int i=x;i>=1;i--){
        printf("%d",a[i]);
    }
    return 0;
}
