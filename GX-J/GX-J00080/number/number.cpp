#include <iostream>
#include <cstring>
using namespace std;
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);

int main()
{
    string s[1000005],x[100005];
    for(int i=0;;i++){
            cin>>s[i];
        if(s[i]=="1"||s[i]=="2"||s[i]=="3"||s[i]=="4"||s[i]=="5"||s[i]=="6"||s[i]=="7"||s[i]=="8"||s[i]=="9"||s[i]=="0"){
            x[i]=s[i];
        }
        if(x[i]<x[i+1]){
            x[i]=x[i+1];}
        cout<<x[i];
    }
    return 0;
}
