#include<bits/stdc++.h>
using namespace std;
string s;
long long a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if((int)s[i]>=48&&(int)s[i]<=57){
            int h=s[i]-'0';
            a[h]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
