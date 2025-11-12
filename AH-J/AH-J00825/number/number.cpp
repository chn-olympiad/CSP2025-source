#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int k=sizeof(s);
    int p=0;
    char alist[k]={};
    for(int i=0;i<sizeof(s);i++){
        if(s[i]=="0"||s[i]=="1"||s[i]=="2"||s[i]=="3"||s[i]=="4"||s[i]=="5"||s[i]=="6"||s[i]=="7"||s[i]=="8"||s[i]=="9"){
            char[p]=s[i];
            p++;
        }
        else{
            continue;
        }
    }
    sort(alist);
    for(int j=0;j<k;j++){
        cout<<alist[j];
    }       
    return 0;
}
