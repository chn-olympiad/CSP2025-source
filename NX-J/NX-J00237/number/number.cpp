#include <iostream>
using namespace std;
int main(){
    char s[999],a[999],c[1];
    int b=0;
    cin >> s;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='1' && s[i]<='9') a[b]=s[i];
        b++;
    }
    for(int i=0;i<strlen(a)*strlen(a);i++){
        if(a[i]<a[i+1]){
            c[0]=a[i];
            a[i]=a[i+1];
            a[i+1]=c[0];
        }
    }
    cout<<a;
    return 0;
}