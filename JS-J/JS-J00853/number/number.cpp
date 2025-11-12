#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","m",stdout);
    char c;
    int a[100]={},n=0;
    while(cin>>c){
        if(c>='0'&&c<='9'){
            a[c-'0']++;
            n++;
        }
    }
    if(a[0]==n){
        cout<<0;
        return 0;
    }
    for(int i=9;i>=0;i--){
        if(a[i]!=0){
            for(int j=0;j<a[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
