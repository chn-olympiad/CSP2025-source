#include<bits/stdc++.h>
using namespace std;
string s;
int a,z;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int i;
cin>>s;
for(i=0;i<10000;i++){
    if(s!="1"||s!="2"||s!="3"||s!="4"||s!="5"||s!="6"||s!="7"||s!="8"||s!="9"||s!="0"){
        s.erase(i,1);
    }
}
sort(s,z);
cout<<s;

return 0;
}

