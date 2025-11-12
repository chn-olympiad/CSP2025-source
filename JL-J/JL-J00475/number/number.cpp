#include <iostream>
#include <string>
using namespace std;
string s;
int a[1000005],b[15];
int main(){
    cin>>s;
    for (int i=0;i<s.size();i++){
        if ((s[i]>='0') && (s[i]<='9')){
            a[i]=s[i]-'0';
            b[a[i]]++;
        }
    }
    for (int i=10;i>=0;i--){
        for (int j=1;j<=b[i];j++){
            cout<<i;
        }
    }
    return 0;
}
