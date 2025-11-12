#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int i=0;
    for(i;;i++){
        for(int q=0;q<=9;q++){
            if(s[i]==q){
                cout<<s[i];
               }
            }
    }
    return 0;
}
