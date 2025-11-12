#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;


    cin>>s;
    string b=" ";
    for(int i=0;i<s.size()-1;i++){
       if(s[i]>='0'&&s[i]<='9'){
         b+=s[i];

       }
    }

    string ma='0';
    int s=0;
    for(int i=0;i<b.size()-1;i++){

        for(int i=0;i<b.size()-1;i++){
           if(b[i]>ma){
                ma=b[i];
                s=i;
           }
        }
        cout<<ma;
        ma='0';
        b[s]='0';
    }
    return 0;
}
