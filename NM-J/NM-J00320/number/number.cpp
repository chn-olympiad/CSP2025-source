#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int m[1000000];
    char s[1000000];
    cin>>s;
    int a=0;
    int n=sizeof(s)/sizeof(s[1]);
    for(int i=0;i<=n;i++){
        if('0'<=s[i]||s[i]<='9'){
            m[a]=s[i]-'0';
            a++;
        }
    }
    sort(m[1],m[a],1);
    for(int i=0;i<=a;i++){
        cout<<m[i];
    }

    return 0;
}
