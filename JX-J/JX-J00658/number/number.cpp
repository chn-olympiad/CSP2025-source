#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    char a[1000001];
    int j=1;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(int(s[i])>=48&&int(s[i])<=57){
            a[j]=s[i];
            j++;
        }
    }for(int i=1;i<=j;i++){
        for(int n=1;n<=j;n++){
            if(int(a[n])<int(a[n+1])){
                swap(a[n],a[n+1]);
            }
        }
    }for(int i=1;i<=j;i++){
        cout<<a[i];
    }
    return 0;
}
