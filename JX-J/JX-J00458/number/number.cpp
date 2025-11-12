#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a="";
    cin>>a;
    int s[11]={};
    for(int i=0;i<a.size();i++){
        s[a[i]-48]++;
    }
    for(int i=9;i>=0;i--){
        while(s[i]--){
            cout<<i;
        }
    }
    return 0;

}
