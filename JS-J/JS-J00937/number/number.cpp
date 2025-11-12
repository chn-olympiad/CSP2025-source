#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[1000010];
    cin>>s;
    int n=strlen(s),w=0;
    char a[n]={};
    for(int i=0;i<n;i++){
        if(s[i]=='9'||s[i]=='8'||s[i]=='7'||s[i]=='6'||s[i]=='5'||s[i]=='4'||s[i]=='3'||s[i]=='2'||s[i]=='1'||s[i]=='0'){
            a[w]=s[i];
            w++;
        }
    }
    sort(a,a+w);
    for(int i=w;i>=0;i--){
        cout<<a[i];
    }

    return 0;
}
