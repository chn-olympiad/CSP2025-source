#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i = 0;i<s.size();i++){
        int c = s[i]-'0';
        if(c>=0 &&c<=9)a[c]++;
    }for(int i = 9;i>=0;i--){
        int b = a[i];
        for(int j = 0;j<b;j++){
            cout<<i;
        }
    }
    return 0;
}
