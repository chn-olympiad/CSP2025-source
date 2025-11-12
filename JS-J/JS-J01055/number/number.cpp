#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10];
int main(){
    for(int i=0;i<=9;i++){
        a[i]=0;
    }
    cin>>s;
    for(int i=0;i<s.size();i++){
        int k=int(s[i]);
        if(k>=48&&k<=57){
            a[k-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=a[i];j>=1;j--){
            cout<<i;
        }
    }
}
