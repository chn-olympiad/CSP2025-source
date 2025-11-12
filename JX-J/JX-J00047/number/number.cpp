#include<iostream>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9'){
                for(int i=0;i<s.length();i++){
                    for(int j=0;j<s.length();j++){
                        swap(s[i-1],s[i]);
                    }
                }
                cout<<s[i];
            }
        }
    return 0;
}
