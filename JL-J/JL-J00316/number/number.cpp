#include<bits/stdc++.h>
using namespace std;
string s;
int a[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        int g=int(s[i]);
        if(g>=48&&g<=57){
            a[g-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(a[i]!=0){
            for(int j=1;j<=a[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
