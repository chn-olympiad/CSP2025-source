#include<bits/stdc++.h>
using namespace std;
string s;
unsigned a[60];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int i=s.size()-1;
    for(;i>=0;i--)a[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        for(;a[i]>0;a[i]--)
            printf("%d",i);
    return 0;
}
