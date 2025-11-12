#include "bits/stdc++.h"
using namespace std;
int numberlist[10];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);


    string s;
    cin>>s;

    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            //cout<<s[i]-48<<endl;
            numberlist[s[i]-48]++;
        }
    }

    for(int i=9;i>=0;i--){
        for(int j=0;j<numberlist[i];j++){
            cout<<i;
        }
    }

    return 0;
}
