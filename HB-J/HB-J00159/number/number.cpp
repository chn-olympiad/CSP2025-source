#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1145200],c=0;
    string s;
    cin>>s;
    for(int i=0;i<60000;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[c]=s[i]-'0';
            c++;
        }
    }
    sort(a,a+c);
    for(int i=c-1;i>=0;i--)
        printf("%d",a[i]);

}
