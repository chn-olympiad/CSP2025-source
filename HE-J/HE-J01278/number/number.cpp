#include<iostream>
#include<cstring>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=9;i>=0;i--){
        for(int j=0;j<s.size();j++){
            if(int(s[j])-48==i){
                cout<<i;
                s[j]='n';
            }
        }
    }
    return 0;
}
