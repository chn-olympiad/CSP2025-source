#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.size();i++){
        if(48<=s[i]<=57){
            a[s[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
