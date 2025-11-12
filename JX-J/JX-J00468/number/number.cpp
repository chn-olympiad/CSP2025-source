#include<bits/stdc++.h>
using namespace std;
string s="";
char c;
int a[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        c=s[i];
        if(c>='0'&&c<='9') a[c-'0']++;
    }
    for(int i=9;i>=0;i--){
        if(a[i]>0){

            for(int j=0;j<a[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
