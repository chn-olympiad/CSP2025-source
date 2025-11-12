#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int b=s.size(),i,k=1;
    int a[b+1]={0};
    for(i=0; i<=b; i++){
        if(isinteger(s[i]-'1')){
             a[k]=s[i]-'1';
             k++;
        }
    sort(a+1,a+k);
    for(i=k; i>=0; i--) cout<<a[i];
}
