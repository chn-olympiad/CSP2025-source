#include <iostream>
using namespace std;
string n;
int i,j[10],p;
int main (){
    cin>>n;
    for(i=0;i<=n.size();i++){
        if(n[i]>='0' && n[i]<='9'){
            j[n[i]-'0'];
        }
    }
    for(i=9;i>=0;i--){
       for(p=0;p<j[i];p++){
           cout<<i;
       }
    }
return 0;
}
