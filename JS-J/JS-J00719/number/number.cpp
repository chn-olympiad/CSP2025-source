#include<bits/stdc++.h>
using namespace std;
int a[1000];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        a[s[i]-48]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++)printf("%d",i);
    }
    return 0;
}
