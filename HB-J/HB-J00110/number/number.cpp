#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string a;
    int n[100005];
    cin>>a;
    int c=1;
    int cn=0;
    for(int i=0;i<=a.length();i++){
        if(int(a[i])>=48&&int(a[i])<=57){
            n[c]=a[i];
            c+=1;
            cn+=1;
        }
    }
    for(int i=1;i<=cn;i++){
        n[i]=n[i]-48;
    }
    for(int i=1;i<=cn;i++){
        for(int j=1;j<=cn;j++){
            if(n[j]<n[j+1]){
                swap(n[j],n[j+1]);
            }
        }
    }
    for(int i=1;i<=cn;i++){
        cout<<n[i];
    }
    return 0;
}
